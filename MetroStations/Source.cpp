#include <stdio.h>
#include <math.h>

struct MetroStation
{
	int AmountOfPeople = 50;
	float TicketPrice = 1000 / AmountOfPeople;
};

MetroStation ChangeTicketPrice(MetroStation station)
{
	station.TicketPrice = 1000 / station.AmountOfPeople;
	return station;
}

int main()
{
	int Arrivals;
	MetroStation Mayakovskaya, Pushkinskaya;
	printf("enter amout of people that arrived on the first station\n");
	scanf_s("%d", &Arrivals);
	Mayakovskaya.AmountOfPeople = Mayakovskaya.AmountOfPeople + Arrivals;
	Mayakovskaya = ChangeTicketPrice(Mayakovskaya);
	printf("TicketPrice on the first station is %f\n", Mayakovskaya.TicketPrice);
	printf("enter amout of people that arrived on the second station\n");
	scanf_s("%d", &Arrivals);
	Pushkinskaya.AmountOfPeople = Pushkinskaya.AmountOfPeople + Arrivals;
	Pushkinskaya = ChangeTicketPrice(Pushkinskaya);
	printf("TicketPrice on the second station is %f\n", Pushkinskaya.TicketPrice);
	return 0;
}