//--------------------------------------------------------------------------------
#define AB 7
#define BUF 6
#define GA 5
#define SHDN 4
#define SS 2
//--------------------------------------------------------------------------------
unsigned int mcp4921_convert(float Dout, float Vref)
{
	unsigned int Vout = (unsigned int)((Dout/Vref*4096));
	return Vout;
}
//--------------------------------------------------------------------------------
void mcp4921_send(unsigned int D)
{
	unsigned int inform = D>>8;
	inform |= ((1<<GA)|(1<<SHDN));
	PORTB &= ~(1<<SS);
	spi_master_send(inform);
	spi_master_send(D);
	PORTB |= (1<<SS);
}
