#define SS PORTB2
#define MOSI PORTB3
#define MISO PORTB4
#define SCK PORTB5
#define Fosc (1<<SPR1)|(1<<SPI2X)
//-------------------------------------------
void spi_master_init()
{
	DDRB |= (1<<SS)|(1<<MOSI)|(1<<SCK);
	PORTB &= ~((1<<SS)|(1<<MOSI)|(1<<SCK));
	SPCR = (1<<SPE)|(1<<MSTR)|Fosc;// fosc/32
}
//-------------------------------------------
void spi_master_send(char data)
{
	SPDR = data;
	while(!(SPSR&(1<<SPIF)));
}
//-------------------------------------------
void spi_slave_init()
{
	DDRB &= ~((1<<SS)|(1<<MOSI)|(1<<SCK));
	PORTB &= ~((1<<SS)|(1<<MOSI)|(1<<SCK));
	SPCR = (1<<SPE)|(1<<SPIE);
}