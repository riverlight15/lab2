
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

// amount of memory to be allocated for heap storage must be specified for every ANSI C++ program with the bur_heap_size variable
unsigned long bur_heap_size = 0xFFFF; 

void _INIT ProgramInit(void)
{
	driveSM.enable = 1;	// Insert code here 

}

void _CYCLIC ProgramCyclic(void)
{
	DoorStateMachine (&doorSM);
	driveSM.speed=doorSM.speed;
	DriveStateMachine(&driveSM);
	ledSM.state = doorSM.state;
	LedStateMachine(&ledSM);
	L1=ledSM.led1;
	L2=ledSM.led2;
	L3=ledSM.led3;
	L4=ledSM.led4;
}

void _EXIT ProgramExit(void)
{
	// Insert code here 

}
