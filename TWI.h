//----------------------------------------
void twi_init(void)
{
	TWBR=0b00001100; 
}
//----------------------------------------
void twi_start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));
}
//----------------------------------------
void twi_stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
//----------------------------------------
void twi_send(unsigned char c)
{
	TWDR = c;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
}
