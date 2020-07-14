//----------------------------------------
unsigned int mcp4725_convert(float Dout, float Vref)
{
	unsigned int Vout = (unsigned int)((Dout/Vref*4096));
	return Vout;
}
//----------------------------------------
void mcp4725_send(unsigned int D)
{
	unsigned int inform = (D>>8);
	twi_start();
	twi_send(0b11000000);
	twi_send(inform);
	twi_send(D);
	twi_stop();
}