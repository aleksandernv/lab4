
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#include <stdio.h>
#include <stdlib.h>
#endif


int sign(REAL x)
{
	if(x > 0)
		return 1;
	if(x < 0)
		return -1;
	else
		return 0;
}





void _CYCLIC ProgramCyclic(void)
{
	URTK(&URTK1);
	
	URTKView_0 .InstRef = URTK1.InstRef;
	
	URTKView(&URTKView_0 );
	
	urtk_out.internal_axisZ1 = URTK1.internal_axisZ1 + 252.315;
	urtk_out.internal_axisZ2 = URTK1.internal_axisZ2 + 336.641;
	urtk_out.internal_axisZ3 = URTK1.internal_axisZ3-50.1246;
	urtk_out.internal_axisY1 = URTK1.internal_axisY1 + 280.678;
	urtk_out.internal_axisY2 = URTK1.internal_axisY2 + 114.875;
	urtk_out.internal_axisY3 = URTK1.internal_axisY3 - 267.531;
	urtk_out.internal_Ground1 = URTK1.internal_Ground1 + 241.35;
	urtk_out.internal_Ground2 = URTK1.internal_Ground2 + 20.735;
	urtk_out.internal_Ground3 = URTK1.internal_Ground3 - 50.4717;
	urtk_out.internal_movementX1 = URTK1.internal_movementX1 + 253.027;
	urtk_out.internal_movementX2 = URTK1.internal_movementX2 + 38.0305;
	urtk_out.internal_movementX3 = URTK1.internal_movementX3 - 49.6654;
	urtk_out.internal_movementY1 = URTK1.internal_movementY1 + 281.057;
	urtk_out.internal_movementY2 = URTK1.internal_movementY2 + 116.335;
	urtk_out.internal_movementY3 = URTK1.internal_movementY3 - 48;
	urtk_out.internal_movementZ1 = URTK1.internal_movementZ1 + 252.937;
	urtk_out.internal_movementZ2 = URTK1.internal_movementZ2 + 117;
	urtk_out.internal_movementZ3 = URTK1.internal_movementZ3 - 48.6654;
	
	if (urtk_out.internal_movementX1 <= 80)
	{
		sensorX1 = 1;
		if (URTK1.Xinputvelocity > 0)
			URTK1.Xinputvelocity = 0;
	}
	
	if (urtk_out.internal_movementX1 >= 340)
	{
		sensorX2 = 1;
		if (URTK1.Xinputvelocity < 0)
			URTK1.Xinputvelocity = 0;
	}
	
	if (urtk_out.internal_movementX1 >= 80 && urtk_out.internal_movementX1 <= 340)
	{
		sensorX1 = 0;
		sensorX2 = 0;
	}
	
	if (urtk_out.internal_movementZ2 <= 130)
	{
		sensorY1 = 1;
		if (URTK1.Zimputevelocity < 0)
			URTK1.Zimputevelocity = 0;
	}
	
	if (urtk_out.internal_movementZ2 >= 390)
	{
		sensorY2 = 1;
		if (URTK1.Zimputevelocity > 0)
			URTK1.Zimputevelocity = 0;
	}
	
	if (urtk_out.internal_movementZ2 >= 130 && urtk_out.internal_movementZ2 <= 390)
	{
		sensorY1 = 0;
		sensorY2 = 0;
	}
	
	if (urtk_out.internal_axisY3 <= -255)
	{
		sensorZ1 = 1;
		if (URTK1.Yimputvelocity < 0)
			URTK1.Yimputvelocity = 0;
	}
	
	if (urtk_out.internal_axisY3 >= 10)
	{
		sensorZ2 = 1;
		if (URTK1.Yimputvelocity > 0)
			URTK1.Yimputvelocity = 0;
	}
	
	if (urtk_out.internal_axisY3 >= -255 && urtk_out.internal_axisY3 <= 10)
	{
		sensorZ1 = 0;
		sensorZ2 = 0;
	}
	
	int max_speed = 1000;
	
	if (URTK1.Xinputvelocity>max_speed)
		URTK1.Xinputvelocity = max_speed;
	if (URTK1.Xinputvelocity<-max_speed)
		URTK1.Xinputvelocity = -max_speed;
		
	if (URTK1.Zimputevelocity>max_speed)
		URTK1.Zimputevelocity = max_speed;
	if (URTK1.Zimputevelocity<-max_speed)
		URTK1.Zimputevelocity = -max_speed;
		
	if (URTK1.Yimputvelocity>max_speed)
		URTK1.Yimputvelocity = max_speed;
	if (URTK1.Yimputvelocity<-max_speed)
		URTK1.Yimputvelocity = -max_speed;
	
	// G-CODE
	if (flag_wait == 3)
	{
		if((g_command[0] == 'G') && (g_command[1] == '0') && (g_command[2] == '1') && (g_command[4] == 'X') && (g_command[9] == 'Y') && (g_command[14] == 'Z') && (g_command[19] == 'F'))
		{ 
			string_to_number[0] = g_command[5];
			string_to_number[1] = g_command[6];
			string_to_number[2] = g_command[7];
			string_to_number[3] = ' ';
			X_target = strtol(string_to_number, NULL, 10);
			
			string_to_number[0] = g_command[10];
			string_to_number[1] = g_command[11];
			string_to_number[2] = g_command[12];
			string_to_number[3] = ' ';
			Y_target = strtol(string_to_number, NULL, 10);
			
			string_to_number[0] = g_command[15];
			string_to_number[1] = g_command[16];
			string_to_number[2] = g_command[17];
			string_to_number[3] = ' ';
			Z_target = strtol(string_to_number, NULL, 10);
			
			string_to_number[0] = g_command[20];
			string_to_number[1] = g_command[21];
			string_to_number[2] = g_command[22];
			string_to_number[3] = g_command[23];
			V = strtol(string_to_number, NULL, 10);
			
			URTK1.Xinputvelocity = V * sign(X_target - X);
			URTK1.Yimputvelocity = V * sign(Y_target - Y);
			URTK1.Zimputevelocity = V * sign(Z_target - Z); 
			
			flag_wait = 0;
			
			if (URTK1.Xinputvelocity == 0)
				flag_wait += 1;
			if (URTK1.Yimputvelocity == 0)
				flag_wait += 1;
			if (URTK1.Zimputevelocity == 0)
				flag_wait += 1;
		}
	}
	
	X += URTK1.Xinputvelocity / 2660;
	if(URTK1.Yimputvelocity > 0)
		Y += URTK1.Yimputvelocity / 2730;
	else
		Y += URTK1.Yimputvelocity / 2500;
	if(URTK1.Zimputevelocity > 0)
		Z += URTK1.Zimputevelocity / 2760;
	else
		Z += URTK1.Zimputevelocity / 2500;
	
	if ((X_target - X < 1) && (X_target - X > -1) && (URTK1.Xinputvelocity != 0))
	{
		URTK1.Xinputvelocity = 0;
		flag_wait += 1;
	}
	if ((Y_target - Y < 1) && (Y_target - Y > -1) && (URTK1.Yimputvelocity != 0))
	{
		URTK1.Yimputvelocity = 0;
		flag_wait += 1;
	}
	if ((Z_target - Z < 1) && (Z_target - Z > -1) && (URTK1.Zimputevelocity != 0))
	{
		URTK1.Zimputevelocity = 0;
		flag_wait += 1;		
	}
}
