#include "headers/sre_can.h"

// can variables
int can_socket;
struct sockaddr_can addr;
struct ifreq ifr;

// CAN STRUCTS
union HSC_Vehicle_Status_UNION HSC_Vehicle_Status;
union HSC_DriverInput_UNION HSC_DriverInput;
union HSC_Steering_UNION HSC_Steering;
union LOG_BrakePressures_UNION LOG_BrakePressures;
union DV_System_Status_UNION DV_System_Status;
union LOG_LEM_UNION LOG_LEM;
union GW_Battery_Status_UNION GW_Battery_Status;
union DV_ASB_Pressure_UNION DV_ASB_Pressure;
union DV_ASB_Status_UNION DV_ASB_Status;
union DV_AMI_Status_UNION DV_AMI_Status;
union SAF_AIN_F1_Status_UNION SAF_AIN_F1_Status;
union GW_BATTERY_CELLS_UNION GW_Battery_Cells;
union GW_PE_FrontLeft_UNION GW_PE_FrontLeft;
union GW_PE_FrontRight_UNION GW_PE_FrontRight;
union GW_PE_RearLeft_UNION GW_PE_RearLeft;
union GW_PE_RearRight_UNION GW_PE_RearRight;
union HSC_SBG_EKF_VEL_BODY_UNION HSC_SBG_EKF_VEL_BODY;
union HSC_SBG_ACCEL_UNION HSC_SBG_ACCEL;
union LOG_LEM_UNION LOG_LEM;

can_mapping_t can_mappings[] = {
    {HSC_VEHICLE_STATUS_ID, &HSC_Vehicle_Status, sizeof(HSC_Vehicle_Status)},
    {HSC_DRIVERINPUT_ID, &HSC_DriverInput, sizeof(HSC_DriverInput)},
    {HSC_STEERING_ID, &HSC_Steering, sizeof(HSC_Steering)},
    {LOG_BRAKEPRESSURES_ID, &LOG_BrakePressures, sizeof(LOG_BrakePressures)},
    {DV_SYSTEM_STATUS_ID, &DV_System_Status, sizeof(DV_System_Status)},
    {LOG_LEM_ID, &LOG_LEM, sizeof(LOG_LEM)},
    {GW_BATTERY_STATUS_ID, &GW_Battery_Status, sizeof(GW_Battery_Status)},
    {DV_ASB_PRESSURE_ID, &DV_ASB_Pressure, sizeof(DV_ASB_Pressure)},
    {DV_ASB_STATUS_ID, &DV_ASB_Status, sizeof(DV_ASB_Status)},
    {DV_AMI_STATUS_ID, &DV_AMI_Status, sizeof(DV_AMI_Status)},
    {SAF_AIN_F1_STATUS_ID, &SAF_AIN_F1_Status, sizeof(SAF_AIN_F1_Status)},
    {GW_BATTERY_CELLS_ID, &GW_Battery_Cells, sizeof(GW_Battery_Cells)},
    {GW_PE_FRONTLEFT_ID, &GW_PE_FrontLeft, sizeof(GW_PE_FrontLeft)},
    {GW_PE_FRONTRIGHT_ID, &GW_PE_FrontRight, sizeof(GW_PE_FrontRight)},
    {GW_PE_REARLEFT_ID, &GW_PE_RearLeft, sizeof(GW_PE_RearLeft)},
    {GW_PE_REARRIGHT_ID, &GW_PE_RearRight, sizeof(GW_PE_RearRight)},
    {HSC_SBG_EKF_VEL_BODY_ID, &HSC_SBG_EKF_VEL_BODY, sizeof(HSC_SBG_EKF_VEL_BODY)},
    {HSC_SBG_ACCEL_ID, &HSC_SBG_ACCEL, sizeof(HSC_SBG_ACCEL)},
    {LOG_LEM_ID, &LOG_LEM, sizeof(LOG_LEM)},
};

void can_loop() {
    while(1) {
        read_and_match();

        usleep(10000);
    }
}

uint8_t read_and_match()
{
    struct can_frame frame;
    // printf("reading...\n");
    // Read a CAN frame from the socket
    int nbytes = read(can_socket, &frame, sizeof(struct can_frame));
    if(nbytes < 0) {
        perror("Error in reading");
        return 0;
    }

    // Find the corresponding union for the CAN ID
    for (size_t i = 0; i < NUM_MAPPINGS; i++) {
        if (can_mappings[i].can_id == frame.can_id) {
            // Update the union with the CAN frame data
            memcpy(can_mappings[i].union_ptr, frame.data, can_mappings[i].union_size);
            // printf("CAN ID: %x\n", frame.can_id);
            return 0;
        }
    }

    printf("Unknown CAN ID: %x\n", frame.can_id);
    return 1;
}

void setup_can()
{
    printf("Setting up CAN...\n");
    // Create a socket
    if((can_socket = socket (PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("Error while opening socket");
        return;
    }

    // Specify the CAN interface name
    strcpy(ifr.ifr_name, "vcan0");
    ioctl(can_socket, SIOCGIFINDEX, &ifr);

    // Initialize the address structure
    memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    // Bind the socket to the CAN interface
    if(bind(can_socket, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error in socket bind");
        return;
    }
}

void close_can()
{
    printf("closing CAN...\n");
    // Close the socket
    if (close(can_socket) < 0) {
        perror("Error in closing socket");
        return;
    }
}
