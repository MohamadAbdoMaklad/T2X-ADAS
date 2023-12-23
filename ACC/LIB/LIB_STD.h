/************************************************/
/*Author	            : Mohamad Abdo Maklad	*/
/*Date		            : 17-10-2023		 	*/
/*Last Modification	    : 				 		*/
/*Version	            : V01					*/
/************************************************/
/******(Standard types for AVR)******************/
/************************************************/
#ifndef LIB_STD_H
#define LIB_STD_H

typedef unsigned char 		u8;
typedef unsigned short int 	u16;
typedef unsigned long int 	u32;

typedef signed char 		s8;
typedef signed short int 	s16;
typedef signed long int 	s32;

typedef float 				f32;
typedef double 				f64;

//pointers to functions types
typedef void (*v_P2F_v  )(void);
typedef u8   (*U8_P2F_v )(void);
typedef u16  (*U16_P2F_v)(void);
typedef u32  (*U32_P2F_v)(void);
typedef void (*v_P2F_u8)(u8); 
typedef void (*v_P2F_u16)(u16);

// booleans_t
typedef enum
{
	LOW  = 0,
	HIGH = 1,
} BOOL_t;

typedef enum
{
	Disable = 0,
	Enable  = 1,
}STATE_t;
#define EnableState		1
#define DisableState	2
typedef enum
{
	RevEnable=0,
	RevDisable=1,
}ReversedState_t;

// Null def if not def
#ifndef NULL
#define NULL ((void *)0)
#endif

#endif
