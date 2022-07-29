

#include <Arduino.h>
#include <connection.h>
#include <firststart.h>
#include <thermal.h>
#include <hardware.h>


void setup()
{
	//Iniciar os componentes de hardware
	initHardware();

	//Verificar se a atualização do firmware foi concluída
	checkFWUpgrade();


	if (checkNoDisplay())
		serialInit();


	checkHardware();

	if (checkFirstStart())
		firstStart();

	
	readEEPROM();

	
	if (checkLiveModeHelper())
		liveModeHelper();

	
	liveMode();
}

