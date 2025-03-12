#include "headers/sre_can.h"

// can variables
int can_socket;
struct sockaddr_can addr;
struct ifreq ifr;

// CAN STRUCTS
struct HSC_Vehicle_Status_Struct HSC_Vehicle_Status;
struct HSC_DriverInput_Struct HSC_DriverInput;
struct HSC_Steering_Struct HSC_Steering;
struct LOG_BrakePressures_Struct LOG_BrakePressures;
struct DV_System_Status_Struct DV_System_Status;
struct LOG_LEM_Struct LOG_LEM;
struct GW_Battery_Status_Struct GW_Battery_Status;
struct DV_ASB_Pressure_Struct DV_ASB_Pressure;
struct DV_ASB_Status_Struct DV_ASB_Status;
struct DV_AMI_Status_Struct DV_AMI_Status;
struct GW_Battery_Cells_Struct GW_Battery_Cells;
struct GW_PE_FrontLeft_Struct GW_PE_FrontLeft;
struct GW_PE_FrontRight_Struct GW_PE_FrontRight;
struct GW_PE_RearLeft_Struct GW_PE_RearLeft;
struct GW_PE_RearRight_Struct GW_PE_RearRight;
struct HSC_SBG_EKF_Vel_Body_Struct HSC_SBG_EKF_VEL_BODY;
struct HSC_SBG_Accel_Struct HSC_SBG_ACCEL;
struct LOG_LEM_Struct LOG_LEM;

can_mapping_t can_mappings[] = {
	{HSC_VEHICLE_STATUS_ID, &HSC_Vehicle_Status,
		HSC_Vehicle_Status_UnionToStruct},
	{HSC_DRIVER_INPUT_ID, &HSC_DriverInput,
		HSC_DriverInput_UnionToStruct},
	{HSC_STEERING_ID, &HSC_Steering,
		HSC_Steering_UnionToStruct},
	{LOG_BRAKE_PRESSURES_ID, &LOG_BrakePressures,
		LOG_BrakePressures_UnionToStruct},
	{DV_SYSTEM_STATUS_ID, &DV_System_Status,
		DV_System_Status_UnionToStruct},
	{LOG_LEM_ID, &LOG_LEM,
		LOG_LEM_UnionToStruct},
	{GW_BATTERY_STATUS_ID, &GW_Battery_Status,
		GW_Battery_Cells_UnionToStruct},
	{DV_ASB_PRESSURE_ID, &DV_ASB_Pressure,
		DV_ASB_Pressure_UnionToStruct},
	{DV_ASB_STATUS_ID, &DV_ASB_Status,
		DV_ASB_Status_UnionToStruct},
	{DV_AMI_STATUS_ID, &DV_AMI_Status,
		DV_AMI_Status_UnionToStruct},
	{GW_BATTERY_CELLS_ID, &GW_Battery_Cells,
		GW_Battery_Cells_UnionToStruct},
	{GW_PE_FRONT_LEFT_ID, &GW_PE_FrontLeft,
		GW_PE_FrontLeft_UnionToStruct},
	{GW_PE_FRONT_RIGHT_ID, &GW_PE_FrontRight,
		GW_PE_FrontRight_UnionToStruct},
	{GW_PE_REAR_LEFT_ID, &GW_PE_RearLeft,
		GW_PE_RearLeft_UnionToStruct},
	{GW_PE_REAR_RIGHT_ID, &GW_PE_RearRight,
		GW_PE_RearRight_UnionToStruct},
	{HSC_SBG_EKF_VEL_BODY_ID, &HSC_SBG_EKF_VEL_BODY,
		HSC_SBG_EKF_Vel_Body_UnionToStruct},
	{HSC_SBG_ACCEL_ID, &HSC_SBG_ACCEL,
		HSC_SBG_Accel_UnionToStruct},
	{LOG_LEM_ID, &LOG_LEM,
		LOG_LEM_UnionToStruct},
};

void can_loop()
{
	while(1) {
		read_and_match();

		usleep(10);
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
			// memcpy(can_mappings[i].union_ptr, frame.data, can_mappings[i].union_size);

			// Convert the frame data to a struct
			can_mappings[i].union_to_struct(can_mappings[i].struct_ptr, frame.data);
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
