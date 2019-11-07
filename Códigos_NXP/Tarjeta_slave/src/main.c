/*
 * main implementation: use this 'C' sample to create your own application
 *
 */


#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "WindowLifter.h"
#include "ab_DataTypes.h"

int main(void)
{
	while(TRUE)
	{
		WindowLifter();
	}
	return 0;
}
