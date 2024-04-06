#include <iostream>
#include <string>
using namespace std;

class RAM
{
public:
	void StartDevices()
	{
		cout << "RAM: Start the devices." << endl;
	}
	void Analysis()
	{
		cout << "RAM: Memory analysis." << endl;
	}
	void Cleaning()
	{
		cout << "RAM: memory cleaning." << endl;
	}
};

class HardDrive
{
public:
	void Launch()
	{
		cout << "Hard drive: start." << endl;
	}
	void CheckBootSector()
	{
		cout << "Hard drive: Check the boot sector." << endl;
	}
	void Stop()
	{
		cout << "Hard drive: stop the device." << endl;
	}
};

class OpticalDiskReader
{
public:
	void Launch()
	{
		cout << "Optical disk reader: start." << endl;
	}
	void CheckDiskAvailability()
	{
		cout << "Optical disc reader: check for disk availability." << endl;
	}
	void Stop()
	{
		cout << "Optical disc reader: return to original position." << endl;
	}
};

class PowerSupply
{
public:
	void GetPower()
	{
		cout << "Power supply: get power." << endl;
	}
	void PowerGraphicsCard()
	{
		cout << "Power supply: power to the video card." << endl;
	}
	void PowerRAM()
	{
		cout << "Power supply: power the RAM." << endl;
	}
	void PowerDiskReader()
	{
		cout << "Power supply: power the disk reader." << endl;
	}
	void PowerHardDrive()
	{
		cout << "Power supply: power the hard drive." << endl;
	}
	void StopPowerGraphicsCard()
	{
		cout << "Power supply: stop graphics card power supply." << endl;
	}
	void StopPowerRAM()
	{
		cout << "Power supply: stop the RAM power." << endl;
	}
	void StopPowerDiskReader()
	{
		cout << "Power supply: stop powering the disk reader." << endl;
	}
	void StopPowerHardDrive()
	{
		cout << "Power supply: stop power to the hard drive." << endl;
	}
	void StopPower()
	{
		cout << "Power supply: stop power supply." << endl;
	}
};
class GraphicsCard
{
public:
	void Launch()
	{
		cout << "Graphics card: launch." << endl;
	}
	void CheckConnectionMonitor()
	{
		cout << "Graphics card: checking connection with the monitor." << endl;
	}
	void OutputRAMData()
	{
		cout << "Graphics card: output of RAM data." << endl;
	}
	void DisplayAboutDiskReader()
	{
		cout << "Graphics card: display information about the disk reader." << endl;
	}
	void DisplayAboutHardDrive()
	{
		cout << "Graphics card: display information about the hard drive." << endl;
	}
	void DisplayFarewellMessage()
	{
		cout << "Graphics card: display the data of the farewell message." << endl;
	}
};
class Sensors
{
public:
	void CheckVoltage()
	{
		cout << "Sensors: check voltage." << endl;
	}
	void CheckTempInPowerSupply()
	{
		cout << "Sensors: check the temperature in the power supply." << endl;
	}
	void CheckTempInGraphicsCard()
	{
		cout << "Sensors: check the temperature in the graphics card." << endl;
	}
	void CheckRAMTemperature()
	{
		cout << "Sensors: Check the RAM temperature." << endl;
	}
	void CheckRAMAllSystems()
	{
		cout << "Sensors: check the temperature of all systems." << endl;
	}
};

class PC
{
	RAM ram;
	GraphicsCard graphicsCard;
	HardDrive hardDrive;
	OpticalDiskReader opticalDiskReader;
	PowerSupply powerSupply;
	Sensors sensors;
public:
	void BeginWork()
	{
		powerSupply.GetPower();
		sensors.CheckVoltage();
		sensors.CheckTempInPowerSupply();
		sensors.CheckTempInGraphicsCard();
		powerSupply.PowerGraphicsCard();
		graphicsCard.Launch();
		graphicsCard.CheckConnectionMonitor();
		sensors.CheckRAMTemperature();
		powerSupply.PowerRAM();
		ram.StartDevices();
		ram.Analysis();
		graphicsCard.OutputRAMData();
		powerSupply.PowerDiskReader();
		opticalDiskReader.Launch();
		opticalDiskReader.CheckDiskAvailability();
		graphicsCard.DisplayAboutDiskReader();
		powerSupply.PowerHardDrive();
		hardDrive.Launch();
		hardDrive.CheckBootSector();
		graphicsCard.DisplayAboutHardDrive();
		sensors.CheckRAMAllSystems();
	}
	void StopWork()
	{
		hardDrive.Stop();
		ram.Cleaning();
		ram.Analysis();
		graphicsCard.DisplayFarewellMessage();
		opticalDiskReader.Stop();
		powerSupply.StopPowerGraphicsCard();
		powerSupply.StopPowerRAM();
		powerSupply.StopPowerDiskReader();
		powerSupply.StopPowerHardDrive();
		sensors.CheckVoltage();
		powerSupply.StopPower();
	}
};
int main()
{
	PC pc;
	pc.BeginWork();
	pc.StopWork();
	system("pause");
	return 0;
}