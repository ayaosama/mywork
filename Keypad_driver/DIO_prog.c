/*
 * DIO_prog.c
 *
 *  Created on: Jan 27, 2016
 *      Author: 7ossam
 */
#include "Conc.h"
#include "util.h"
#include "Types.h"

#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"


static volatile u8* const DIO_u8PORTADD[DIO_u8PORTSIZE]={DIO_u8PORTA,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PORTD};
static volatile u8* const DIO_u8PINADD[DIO_u8PORTSIZE]={DIO_u8PINA,DIO_u8PINB,DIO_u8PINC,DIO_u8PIND};
static volatile u8* const DIO_u8DDRADD[DIO_u8PORTSIZE]={DIO_u8DDRA,DIO_u8DDRB,DIO_u8DDRC,DIO_u8DDRD};


/*Comment!: Initialization function */
void DIO_voidInit(void)
{
	*DIO_u8DDRA=DIO_u8PORT0DIR;
	*DIO_u8DDRB=DIO_u8PORT1DIR;
	*DIO_u8DDRC=DIO_u8PORT2DIR;
	*DIO_u8DDRD=DIO_u8PORT3DIR;

	*DIO_u8PORTA=(*DIO_u8PORTA & (~*DIO_u8DDRA)) | (DIO_u8PORT0DIR & DIO_u8PORT0INIT);
	*DIO_u8PORTB=(*DIO_u8PORTB & (~*DIO_u8DDRB)) | (DIO_u8PORT1DIR & DIO_u8PORT1INIT);
	*DIO_u8PORTC=(*DIO_u8PORTC & (~*DIO_u8DDRC)) | (DIO_u8PORT2DIR & DIO_u8PORT2INIT);
	*DIO_u8PORTD=(*DIO_u8PORTD & (~*DIO_u8DDRD)) | (DIO_u8PORT3DIR & DIO_u8PORT3INIT);

	return;
}




/*Comment!: Read Port Value */
extern u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx,u8* Copy_u8PtrToVal)
{
	u8 Local_u8Error=u8OK;
	if(Copy_u8PortIdx >= DIO_u8PORTSIZE)
	{
		Local_u8Error=u8ERROR;
	}
	else
	{
		*Copy_u8PtrToVal=*(DIO_u8PINADD[Copy_u8PortIdx]);
	}

	return Local_u8Error;
}


/*Comment!: Write Port Value */
extern u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx,u8 Copy_u8PortVal)
{
	u8 Local_u8Error=u8OK;
	if(Copy_u8PortIdx>=DIO_u8PORTSIZE)
		{
			Local_u8Error = u8ERROR;
		}
	else
		{
			*(DIO_u8PORTADD[Copy_u8PortIdx]) = Copy_u8PortVal;
		}

	return Local_u8Error;
}



/*Comment!: Read Pin Value */
extern u8 DIO_u8ReadPinVal(u8 Copy_u8PinIdx,u8* Copy_u8PtrToVal)
{
	u8 Local_u8Error=u8OK;
	u8 Local_u8PinNum=Copy_u8PinIdx % DIO_u8PINPERPORT;
	u8 Local_u8PortNum=(u8)(Copy_u8PinIdx / DIO_u8PINPERPORT);
	if(Copy_u8PinIdx>=DIO_u8PINSIZE)
		{
			Local_u8Error = u8ERROR;
		}
	else
		{
			*Copy_u8PtrToVal=GETBIT(*(DIO_u8PINADD[Local_u8PortNum]),Local_u8PinNum) ;
		}


	return Local_u8Error;
}


/*Comment!: Write Pin Value */
extern u8 DIO_u8WritePinVal(u8 Copy_u8PinIdx,u8 Copy_u8PinVal)
{
	u8 Local_u8Error=u8OK;
	u8 Local_u8PinNum=Copy_u8PinIdx % DIO_u8PINPERPORT;
	u8 Local_u8PortNum=(u8)(Copy_u8PinIdx / DIO_u8PINPERPORT);
	if(Copy_u8PinIdx>=DIO_u8PINSIZE)
		{
			Local_u8Error = u8ERROR;
		}
	else
		{
			ASSIGNBIT(*(DIO_u8PORTADD[Local_u8PortNum]),Local_u8PinNum,Copy_u8PinVal);
		}

		return Local_u8Error;
}


/*Comment!: Write Pin Direction */
extern u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx,u8 Copy_u8PinDir)
{
	u8 Local_u8Error=u8OK;
	u8 Local_u8PinNum=Copy_u8PinIdx % DIO_u8PINPERPORT;
	u8 Local_u8PortNum=(u8)(Copy_u8PinIdx / DIO_u8PINPERPORT);
	if(Copy_u8PinIdx>=DIO_u8PINSIZE)
		{
			Local_u8Error = u8ERROR;
		}
	else
		{
			ASSIGNBIT(*(DIO_u8DDRADD[Local_u8PortNum]),Local_u8PinNum,Copy_u8PinDir);
		}

	return Local_u8Error;
}


/*Comment!: Write Port Direction */
extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx,u8 Copy_u8PortDir)
{
	u8 Local_u8Error=u8OK;
	if(Copy_u8PortIdx>=DIO_u8PORTSIZE)
		{
			Local_u8Error = u8ERROR;
		}
	else
		{
			*(DIO_u8DDRADD[Copy_u8PortIdx]) = Copy_u8PortDir;
		}
		return Local_u8Error;
}


/*Comment!: Read Pin Direction */
extern u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx,u8* Copy_u8PtrToDir)
{
	u8 Local_u8Error=u8OK;
	u8 Local_u8PinNum=Copy_u8PinIdx % DIO_u8PINPERPORT;
	u8 Local_u8PortNum=(u8)(Copy_u8PinIdx / DIO_u8PINPERPORT);
	if(Copy_u8PinIdx>=DIO_u8PINSIZE)
		{
			Local_u8Error = u8ERROR;
		}
	else
		{
			*Copy_u8PtrToDir=GETBIT(*(DIO_u8DDRADD[Local_u8PortNum]),Local_u8PinNum) ;
		}
	return Local_u8Error;
}


/*Comment!: Read Port Direction */
extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx,u8* Copy_u8PtrToDir)
{
	u8 Local_u8Error=u8OK;
	if(Copy_u8PortIdx >= DIO_u8PORTSIZE)
		{
			Local_u8Error=u8ERROR;
		}
	else
		{
			*Copy_u8PtrToDir=*(DIO_u8DDRADD[Copy_u8PortIdx]);
		}
	return Local_u8Error;
}
