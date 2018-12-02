#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(void)
{ 
	// Vars
	unsigned int position = 0;
	int count[40] = {0};
	float freq;
	int chance;

	// Street names array
	char *streets[40];
	streets[0] = "Go";
	streets[1] = "Crumlin";
	streets[2] = "Community Chest";
	streets[3] = "Kimmage";
	streets[4] = "Income Tax";
	streets[5] = "Busarus";
	streets[6] = "Rathgar";
	streets[7] = "Chance";
	streets[8] = "South Circular Road";
	streets[9] = "Rathmines";
	streets[10] = "Jail";
	streets[11] = "Dawson Street";
	streets[12] = "Electric Company (ESB)";
	streets[13] = "Kildare Street";
	streets[14] = "Nassau Street";
	streets[15] = "Dublin Airport";
	streets[16] = "Pearse Street";
	streets[17] = "Community Chest";
	streets[18] = "Dame Street";
	streets[19] = "Westmoreland Street";
	streets[20] = "Free Parking";
	streets[21] = "Abbey Street";
	streets[22] = "Chance";
	streets[23] = "Capel Street";
	streets[24] = "Henry Street";
	streets[25] = "Heuston Station";
	streets[26] = "Talbot Street";
	streets[27] = "North Earl Street";
	streets[28] = "Water Works (Irish Water)";
	streets[29] = "O'Connel Street";
	streets[30] = "Go To Jail";
	streets[31] = "Georges Street";
	streets[32] = "Wicklow Street";
	streets[33] = "Community Chest";
	streets[34] = "Grafton Street";
	streets[35] = "Shannon Airport";
	streets[36] = "Chance";
	streets[37] = "Ailesbury Road";
	streets[38] = "Super Tax";
	streets[39] = "Shrewsbury Road";

	// Street prices array
	int prices[40];
	prices[0] = 0;
	prices[1] = 60;
	prices[2] = 0;
	prices[3] = 60;
	prices[4] = 200;
	prices[5] = 200;
	prices[6] = 100;
	prices[7] = 0;
	prices[8] = 100;
	prices[9] = 120;
	prices[10] = 0;
	prices[11] = 140;
	prices[12] = 150;
	prices[13] = 140;
	prices[14] = 160;
	prices[15] = 200;
	prices[16] = 180;
	prices[17] = 0;
	prices[18] = 180;
	prices[19] = 200;
	prices[20] = 0;
	prices[21] = 220;
	prices[22] = 0;
	prices[23] = 220;
	prices[24] = 240;
	prices[25] = 200;
	prices[26] = 260;
	prices[27] = 260;
	prices[28] = 150;
	prices[29] = 280;
	prices[30] = 0;
	prices[31] = 300;
	prices[32] = 300;
	prices[33] = 0;
	prices[34] = 320;
	prices[35] = 200;
	prices[36] = 0;
	prices[37] = 350;
	prices[38] = 100;
	prices[39] = 400;

	// Chance cards array
	//int chance[9];
	//chance[0] = 1; // Advance to Go
	//chance[1] = 2; // Advance to Henry Street
	//chance[2] = 3; // Advance to Dawson Street 
	//chance[3] = 4; // Advance to Nearest Utility
	//chance[4] = 5; // Advance to Nearest Railroad
	//chance[5] = 6; // Go back 3 places
	//chance[6] = 7; // Advance to Jail
	//chance[7] = 8; // Advance to Busarus
	//chance[8] = 9; // Advance to Shrewsbury Road


	for (int i = 0; i < 10000; ++i)
	{
		int dice_one = rand() % 7;
		int dice_two = rand() % 7;
		int total_roll = dice_one + dice_two;
		

		position += total_roll;
		//printf("position: %d\n", position);

		// Setting position
		if (position <= 40) {

			//printf("Street: %s\n", streets[--position]);
			++count[--position];
		
		} else {

			position -= 40;
			//printf("Street: %s\n", streets[--position]);
			++count[--position];

		}

		if (position == 7 || position == 22 || position == 36)
		{
			chance = rand() % 10;

   			switch(chance) {
		      case 1 :
		         //printf("Go!\n" );
		         position = 0;
		         break;
		      case 2 :
		         //printf("Henry Street\n" );
		         position = 24;
		         break;
		      case 3 :
		         //printf("Dawson Street\n" );
		         position = 11;
		         break;
		      case 4 :
		         //printf("Nearest Utility" );
		         break;
		      case 5 :
		         //printf("Nearest Railroad\n" );
		         break;
		      case 6 :
		         //printf("Jail!\n" );
		         position = 10;
		         break;
		      case 7 :
		         //printf("Busarus\n" );
		         position = 5;
		         break;
		      case 8 :
		         //printf("Shrewsbury Road\n" );
		         position = 39;
		         break;
		      case 9 :
		         //printf("Shrewsbury Road\n" );
		         position -= 3;
		         break;
		    }
		} else if (position == 30) {
			position = 10;
			//printf("Go To Jail!\n");
		}
	}

	for (int i = 0; i < 40; ++i)
	{
		freq = count[i] / 10000.0f;
		printf("Freq Of %s: %lf\n", streets[i], freq);
	}
    return 0;

}