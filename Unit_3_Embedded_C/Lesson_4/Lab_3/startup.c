

//Startup.c
//Eng.Mina Fathy

#include "Platform_Types.h"

void Reset_Handler();
extern int main(void);

//booking of 1024B by .bss through unintialized array of int 256 Element (256*4 = 1024)
static vuint32_t stack_top[256];

void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler() __attribute__((weak, alias("Default_Handler")));
void H_fault_Handler() __attribute__((weak, alias("Default_Handler")));
void MM_fault_Handler() __attribute__((weak, alias("Default_Handler")));
void Bus_fault_Handler() __attribute__((weak, alias("Default_Handler")));
void Usage_fault_Handler() __attribute__((weak, alias("Default_Handler")));

void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors")))= {

(void(*)())((vuint32_t)stack_top + sizeof(stack_top)),
&Reset_Handler,
&NMI_Handler,
&H_fault_Handler,
&MM_fault_Handler,
&Bus_fault_Handler,
&Usage_fault_Handler

};

extern uint32 _E_text;
extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_bss;
extern uint32 _E_bss;

void Reset_Handler()
{
	
	//copy data section from flash to ram
	vuint32_t DATA_size = (uint8*)&_E_DATA - (uint8*)&_S_DATA;
	
	vuint8_t *P_src = (uint8*)&_E_text;
	vuint8_t *P_dst = (uint8*)&_S_DATA;
	
	vuint32_t i;
	for(i = 0; i < DATA_size; i++)
	{
		*((vuint8_t *)P_dst++) = *((vuint8_t *)P_src++);
	}
	
	//initialize .bss in sram = 0
	vuint32_t bss_size = (uint8*)&_E_bss - (uint8*)&_S_bss;
	P_dst = (uint8*)&_S_bss;
	for(i = 0; i < bss_size; i++)
	{
		*((vuint8_t *)P_dst++) = (uint8)0;
	}
	//jump main()
	main();
} 