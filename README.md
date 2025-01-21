# THIS REPO HAS BEEN MOVED
repo can be found at https://github.com/SchanzerRacing/sre_driver_display


## gtk-driver-display
Playing around and testing gtk for use in a Formula Student Driver Display


## Architecture

One GUI thread, one CAN Thread.

GUI thread handles all things GUI, CAN thread all things CAN.

CAN thread continuously reads all CAN messages and saves the newest message into the shared memory.
-> one message struct per ID. this struct allways contains the newest message.
-> this thread could also do error checking if necessary

GUI thread reads the shared memory every x seconds and updates the GUI accordingly.
