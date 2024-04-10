#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Processor;
class Hdd;
class RAM;
class GPU;

class IVisitor abstract
{
public:
	virtual void VisitProcessor(Processor* proc) abstract;
	virtual void VisitHdd(Hdd* hdd) abstract;

	virtual void VisitRAM(RAM* ram) abstract;
	virtual void VisitGPU(GPU* grcard) abstract;
};

class AbstractDevice abstract
{
	string Producer;
public:
	virtual void Accept(IVisitor* visitor)abstract;
	string GetProducer()
	{ 
		return Producer;
	}
	void SetProducer(string Producer)
	{
		this->Producer = Producer;
	}
};

class Processor: public AbstractDevice
{
	string Frequency;
	string CoreCount;
public:
	string GetFrequency()
	{
		return  Frequency;
	}
	void SetFrequency(string Frequency)
	{
		this->Frequency = Frequency;
	}
	string GetCoreCount()
	{
		return CoreCount;
	}
	void SetCoreCount(string CoreCount)
	{
		this->CoreCount = CoreCount;
	}
	void Accept(IVisitor* visitor) override
	{
		visitor->VisitProcessor(this);
	}
};

class RAM : public AbstractDevice
{
	string Frequency;
	string CoreCount;
public:
	string GetFrequency()
	{
		return  Frequency;
	}
	void SetFrequency(string Frequency)
	{
		this->Frequency = Frequency;
	}
	string GetCoreCount()
	{
		return CoreCount;
	}
	void SetCoreCount(string CoreCount)
	{
		this->CoreCount = CoreCount;
	}
	void Accept(IVisitor* visitor) override
	{
		visitor->VisitRAM(this);
	}
};
class GPU : public AbstractDevice
{
	string Frequency;
	string CoreCount;
public:
	string GetFrequency()
	{
		return  Frequency;
	}
	void SetFrequency(string Frequency)
	{
		this->Frequency = Frequency;
	}
	string GetCoreCount()
	{
		return CoreCount;
	}
	void SetCoreCount(string CoreCount)
	{
		this->CoreCount = CoreCount;
	}
	void Accept(IVisitor* visitor) override
	{
		visitor->VisitGPU(this);
	}
};

class Hdd: public AbstractDevice
{
	string Volume;
	string Type;
public:
	string GetVolume()
	{
		return Volume;
	}
	void SetVolume(string Volume)
	{
		this->Volume = Volume;
	}
	string GetType()
	{
		return Type;
	}
	void SetType(string Type)
	{
		this->Type = Type;
	}
	void Accept(IVisitor* visitor) override
	{
		visitor->VisitHdd(this);
	}
};

// сериализатор в HTML
class HtmlVisitor : public IVisitor
{
public:
	void VisitProcessor(Processor* proc) override
	{
		ofstream out("Processor.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + proc->GetProducer() + "</td></tr>";
		result += "<tr><td>Frequency<td><td>" + proc->GetFrequency() + "</td></tr>";
		result += "<tr><td>CoreCount<td><td>" + proc->GetCoreCount() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitHdd(Hdd* hdd) override
	{
		ofstream out("Hdd.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + hdd->GetProducer() + "</td></tr>";
		result += "<tr><td>Type<td><td>" + hdd->GetType() + "</td></tr>";
		result += "<tr><td>Volume<td><td>" + hdd->GetVolume() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitRAM(RAM* ram) override
	{
		ofstream out("Processor.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + ram->GetProducer() + "</td></tr>";
		result += "<tr><td>Frequency<td><td>" + ram->GetFrequency() + "</td></tr>";
		result += "<tr><td>CoreCount<td><td>" + ram->GetCoreCount() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitGPU(GPU* grcard) override
	{
		ofstream out("Processor.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + grcard->GetProducer() + "</td></tr>";
		result += "<tr><td>Frequency<td><td>" + grcard->GetFrequency() + "</td></tr>";
		result += "<tr><td>CoreCount<td><td>" + grcard->GetCoreCount() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}
};

// сериализатор в XML
class XmlVisitor: public IVisitor
{
public:
	void VisitProcessor(Processor* proc) override
	{
		ofstream out("Processor.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<Processor><Producer>" + proc->GetProducer() + "</Producer>" +
			"<Frequency>" + proc->GetFrequency() + "</Frequency>" +
			"<CoreCount>" + proc->GetCoreCount() + "</CoreCount></Processor>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitHdd(Hdd* hdd) override
	{
		ofstream out("Hdd.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<HDD><Producer>" + hdd->GetProducer() + "</Producer>" +
			"<Type>" + hdd->GetType() + "</Type>" +
			"<Volume>" + hdd->GetVolume() + "</Volume></HDD>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitRAM(RAM* ram) override
	{
		ofstream out("RAM.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<Processor><Producer>" + ram->GetProducer() + "</Producer>" +
			"<Frequency>" + ram->GetFrequency() + "</Frequency>" +
			"<CoreCount>" + ram->GetCoreCount() + "</CoreCount></Processor>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitGPU(GPU* grcard) override
	{
		ofstream out("GPU.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<Processor><Producer>" + grcard->GetProducer() + "</Producer>" +
			"<Frequency>" + grcard->GetFrequency() + "</Frequency>" +
			"<CoreCount>" + grcard->GetCoreCount() + "</CoreCount></Processor>";
		out.write(result.c_str(), result.size());
		out.close();
	}
};
class TxtVisitor : public IVisitor
{
public:
	void VisitProcessor(Processor* proc) override
	{
		ofstream out("Processor.txt", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<Processor><Producer>" + proc->GetProducer() + "</Producer>" +
			"<Frequency>" + proc->GetFrequency() + "</Frequency>" +
			"<CoreCount>" + proc->GetCoreCount() + "</CoreCount></Processor>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitHdd(Hdd* hdd) override
	{
		ofstream out("Hdd.txt", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<HDD><Producer>" + hdd->GetProducer() + "</Producer>" +
			"<Type>" + hdd->GetType() + "</Type>" +
			"<Volume>" + hdd->GetVolume() + "</Volume></HDD>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitRAM(RAM* ram) override
	{
		ofstream out("RAM.txt", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<Processor><Producer>" + ram->GetProducer() + "</Producer>" +
			"<Frequency>" + ram->GetFrequency() + "</Frequency>" +
			"<CoreCount>" + ram->GetCoreCount() + "</CoreCount></Processor>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitGPU(GPU* grcard) override
	{
		ofstream out("GPU.txt", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<Processor><Producer>" + grcard->GetProducer() + "</Producer>" +
			"<Frequency>" + grcard->GetFrequency() + "</Frequency>" +
			"<CoreCount>" + grcard->GetCoreCount() + "</CoreCount></Processor>";
		out.write(result.c_str(), result.size());
		out.close();
	}
};

class PC
{
	vector<AbstractDevice*> devices;
public:
	void Add(AbstractDevice* d)
	{
		devices.push_back(d);
	}
	void Remove(AbstractDevice* d)
	{
		auto iter = find(devices.begin(), devices.end(), d);
		if(iter != devices.end())
			devices.erase(iter);
	}
	void Accept(IVisitor* visitor)
	{
		for(AbstractDevice* d : devices)
			d->Accept(visitor);
	}
};

int main()
{
	PC* pc = new PC();

	Processor *p = new Processor;
	p->SetProducer("Intel");
	p->SetFrequency("3.5");
	p->SetCoreCount("4");
	pc->Add(p);

	Hdd *hdd = new Hdd;
	hdd->SetProducer("Western Digital");
	hdd->SetType("SATA III");
	hdd->SetVolume("2");
	pc->Add(hdd);

	RAM* ram = new RAM;
	ram->SetProducer("Intel");
	ram->SetFrequency("3.5");
	ram->SetCoreCount("4");
	pc->Add(ram);

	GPU* gpu = new GPU;
	gpu->SetProducer("Help");
	gpu->SetFrequency("3.5");
	gpu->SetCoreCount("4");
	pc->Add(gpu);


	HtmlVisitor *html = new HtmlVisitor;
	pc->Accept(html);
	XmlVisitor *xml = new XmlVisitor;
	pc->Accept(xml);
	TxtVisitor* txt = new TxtVisitor;
	pc->Accept(txt);

	delete html;
	delete xml;
	delete txt;

	delete hdd;
	delete p;
	delete pc;
	delete ram;
	delete gpu;



	system("pause");
}
