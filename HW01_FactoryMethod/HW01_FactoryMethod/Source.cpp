#include <iostream>
#include <string>
using namespace std;

class Figure abstract
{
protected:
	int shape[4][4];
	int rgb[3];
	string name = "";
public:
	virtual void SetShape() = 0;
	void SetRgb() {
		for (int i = 0; i < sizeof(rgb) / sizeof(rgb[0]); i++) {
			rgb[i] = 1 + rand() % 255;
		}
	}
	virtual void SetName() = 0;
	void ShowFigure() {
		cout << "Figure name: " + name << "\nRGB: (";
		for (int i = 0;i < sizeof(rgb) / sizeof(rgb[0]); i++) {
			cout << rgb[i];
			if (i != sizeof(rgb) / sizeof(rgb[0])-1)
				cout << "-";
		}
		cout << ")\nShape: "<<endl;
		int shapeSize = sizeof(shape) / sizeof(shape[0]);
		for (int i = 0; i < shapeSize; i++) 
		{
			for (int j = 0; j < shapeSize; j++) {
				if (shape[i][j]==true)
					cout << "[]";
				else
					cout << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}
};

class LFigure : public Figure
{
public:
	void SetShape()override
	{
		shape[0][0] = true; shape[1][0] = true; shape[2][0] = true; shape[2][1] = true;
	}
	void SetName()override
	{
		name = "L-Figure";
	}
};
class OFigure : public Figure
{
public:
	void SetShape()override
	{
		shape[0][0] = true; shape[0][1] = true; shape[1][0] = true; shape[1][1] = true;
	}
	void SetName()override
	{
		name = "O-Figure";
	}
};
class IFigure : public Figure
{
public:
	void SetShape()override
	{
		shape[0][0] = true; shape[1][0] = true; shape[2][0] = true; shape[3][0] = true;
	}
	void SetName()override
	{
		name = "I-Figure";
	}
};
class JFigure : public Figure
{
public:
	void SetShape()override
	{
		shape[0][1] = true; shape[1][1] = true; shape[2][1] = true; shape[2][0] = true;
	}
	void SetName()override
	{
		name = "J-Figure";
	}
};
class ZFigure : public Figure
{
public:
	void SetShape()override
	{
		shape[0][0] = true; shape[0][1] = true; shape[1][1] = true; shape[1][2] = true;
	}
	void SetName()override
	{
		name = "Z-Figure";
	}
};
class TFigure : public Figure
{
public:
	void SetShape()override
	{
		shape[0][1] = true; shape[1][0] = true; shape[1][1] = true; shape[1][2] = true;
	}
	void SetName()override
	{
		name = "T-Figure";
	}
};
class SFigure : public Figure
{
public:
	void SetShape()override
{
		shape[0][1] = true; shape[0][2] = true; shape[1][0] = true; shape[1][1] = true;
	}
	void SetName()override
	{
		name = "S-Figure";
	}
};
 
class Creator abstract
{
public:
	virtual Figure* FactoryMethod() = 0;
};

class CreatorLFigure : public Creator
{
public:
	Figure* FactoryMethod()override
	{
		Figure* figure = new LFigure();
		figure->SetShape();
		figure->SetName();
		return figure;
	}
};
class CreatorOFigure : public Creator
{
public:
	Figure* FactoryMethod()override
	{
		Figure* figure = new OFigure();
		figure->SetShape();
		figure->SetName();
		return figure;
	}
};
class CreatorIFigure : public Creator
{
public:
	Figure* FactoryMethod()override
	{
		Figure* figure = new IFigure();
		figure->SetShape();
		figure->SetName();
		return figure;
	}
};
class CreatorJFigure : public Creator
{
public:
	Figure* FactoryMethod()override
	{
		Figure* figure = new JFigure();
		figure->SetShape();
		figure->SetName();
		return figure;
	}
};
class CreatorZFigure : public Creator
{
public:
	Figure* FactoryMethod()override
	{
		Figure* figure = new ZFigure();
		figure->SetShape();
		figure->SetName();
		return figure;
	}
};
class CreatorTFigure : public Creator
{
public:
	Figure* FactoryMethod()override
	{
		Figure* figure = new TFigure();
		figure->SetShape();
		figure->SetName();
		return figure;
	}
};
class CreatorSFigure : public Creator
{
public:
	Figure* FactoryMethod()override
	{
		Figure* figure = new SFigure();
		figure->SetShape();
		figure->SetName();
		return figure;
	}
};

void Factory(Creator** creators, int size)
{
	for (int i = 0; i < size; i++)
{
		Figure* pc = creators[i]->FactoryMethod();
		pc->SetRgb();
		pc->ShowFigure();
	}
}

void main()
{
	srand(time(NULL));
	Creator* creators[7];
	creators[0] = new CreatorLFigure();
	creators[1] = new CreatorOFigure();
	creators[2] = new CreatorIFigure();
	creators[3] = new CreatorJFigure();
	creators[4] = new CreatorZFigure();
	creators[5] = new CreatorTFigure();
	creators[6] = new CreatorSFigure();
	Factory(creators, 7);

	system("pause");
}