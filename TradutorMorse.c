/**
*@author: Marco A J Saturnino
*@brief: Neste projeto, um LED externo conectado à GPIO (11, 12 ou 13) será utilizado para 
transmitir o sinal SOS, em código Morse, através de pulsos luminosos contínuos. 
O comportamento do LED deve seguir as seguintes regras:
• Um Ponto (.) é representado pelo LED aceso por 0,2 segundos.
• Um traço(-) é representado pelo LED aceso por 0,8 segundos.
• O intervalo entre PontoLEDs e traços dentro de uma mesma letra é de 0,125 segundos
(tempo GAP).
• O intervalo entre letras deve ser de 0,25 segundos.
• Após completar o sinal SOS (três Pontos, três traços, três Pontos), o ciclo é reiniciado 
após um intervalo de 3 segundos.
*@date: 08/01/2025
*@version 1.0
*/

//Bibliotecas
#include <stdio.h>
#include "pico/stdlib.h"

//Defines, Macros, enum
#define led_pin     13
#define buzzer_b    10
enum estado_gpio 
{
    high = 1u,
    low = 0u,
};

//Escopo de função
void InitSistema();

void TecladoAlfaMorseLED(char _letra);
void PontoLED(void);
void TracoLED(void);
void EspacoLED(void);

void TecladoAlfaMorseBUZ(char _letra);
void PontoBUZ(void);
void TracoBUZ(void);
void EspacoBUZ(void);

void tone(uint gpio, uint freq, uint duration_ms);

//Funções
int main() 
{
    InitSistema();
    sleep_ms(50);
    while (true) 
    {
        printf("SOS Luminoso:\n");
        TecladoAlfaMorseLED('S');
        TecladoAlfaMorseLED('O');
        TecladoAlfaMorseLED('S');
        printf("\n");
        
        printf("SOS Sonoro:\n");
        TecladoAlfaMorseBUZ('S');
        TecladoAlfaMorseBUZ('O');
        TecladoAlfaMorseBUZ('S');
        printf("\n");
        sleep_ms(3000);
    }
}

void InitSistema()
{
    gpio_init(led_pin);
    gpio_init(buzzer_b);
    gpio_set_dir(led_pin, GPIO_OUT);
    gpio_set_dir(buzzer_b, GPIO_OUT);
    
    stdio_init_all();
}

void TecladoAlfaMorseLED(char _letra)
{
    switch (_letra)
    {
        case 'A':
            //.-
            PontoLED();
            TracoLED();
            EspacoLED();
            break;
        case 'B':
            //-...
            TracoLED();
            PontoLED();
            PontoLED();
            PontoLED();
            EspacoLED();
            break;
        case 'C':
            //-.-.
            TracoLED();
            PontoLED();
            TracoLED();
            PontoLED();
            EspacoLED();
            break;
        case 'D':
            //-..
            TracoLED();
            PontoLED();
            PontoLED();
            EspacoLED();
            break;
        case 'E':
            //.
            PontoLED();
            EspacoLED();
            break;
        case 'F':
            //..-.
            PontoLED();
            PontoLED();
            TracoLED();
            PontoLED();
            EspacoLED();
            break;
        case 'G':
            //--.
            TracoLED();
            TracoLED();
            PontoLED();
            EspacoLED();
            break;
        case 'H':
            //....
            PontoLED();
            PontoLED();
            PontoLED();
            PontoLED();
            EspacoLED();
            break;
        case 'I':
            //..
            PontoLED();
            PontoLED();
            EspacoLED();
            break;
        case 'J':
            //.---
            PontoLED();
            TracoLED();
            TracoLED();
            TracoLED();
            EspacoLED();
            break;
        case 'K':
            //-.-
            TracoLED();
            PontoLED();
            TracoLED();
            EspacoLED();
            break;
        case 'L':
            //.-..
            PontoLED();
            TracoLED();
            PontoLED();
            PontoLED();
            EspacoLED();
            break;
        case 'M':
            //--
            TracoLED();
            TracoLED();
            EspacoLED();
            break;
        case 'N':
            //-.
            TracoLED();
            PontoLED();
            EspacoLED();
            break;
        case 'O':
            //---
            TracoLED();
            TracoLED();
            TracoLED();
            EspacoLED();
            break;
        case 'P':
            //.--.
            PontoLED();
            TracoLED();
            TracoLED();
            PontoLED();
            EspacoLED();
            break;
        case 'Q':
            //--.-
            TracoLED();
            TracoLED();
            PontoLED();
            TracoLED();
            EspacoLED();
            break;
        case 'R':
            //.-.
            PontoLED();
            TracoLED();
            PontoLED();
            EspacoLED();
            break;
        case 'S':
            //...
            PontoLED();
            PontoLED();
            PontoLED();
            EspacoLED();
            break;
        case 'T':
            //-
            TracoLED();
            EspacoLED();
            break;
        case 'U':
            //..-
            PontoLED();
            PontoLED();
            TracoLED();
            EspacoLED();
            break;
        case 'V':
            //...-
            PontoLED();
            PontoLED();
            PontoLED();
            TracoLED();
            EspacoLED();
            break;
        case 'W':
            //.--
            PontoLED();
            TracoLED();
            TracoLED();
            EspacoLED();
            break;
        case 'X':
            //-..-
            TracoLED();
            PontoLED();
            PontoLED();
            TracoLED();
            EspacoLED();
            break;
        case 'Y':
            //-.--
            TracoLED();
            PontoLED();
            TracoLED();
            TracoLED();
            EspacoLED();
            break;
        case 'Z':
            //--..
            TracoLED();
            TracoLED();
            PontoLED();
            PontoLED();
            EspacoLED();
            break;
        default:
            gpio_put(led_pin, high);
            tone(buzzer_b, 1000, 3000);
            break;
        }
};

void PontoLED()
{
    //Um Ponto(.) é representado pelo LED aceso por 0,2 segundos.
    gpio_put(led_pin, high);
    sleep_ms(200);
    gpio_put(led_pin, low);
    sleep_ms(125);
    printf(".");
}

void TracoLED()
{
    //Um traço(-) é representado pelo LED aceso por 0,8 segundos.
    gpio_put(led_pin, high);
    sleep_ms(800);
    gpio_put(led_pin, low);
    sleep_ms(125);
    printf("-");
}

void EspacoLED()
{
    //O intervalo entre letras deve ser de 0,25 segundos.
    sleep_ms(125);
}

void TecladoAlfaMorseBUZ(char _letra)
{
    switch (_letra)
    {
        case 'A':
            //.-
            PontoBUZ();
            TracoBUZ();
            EspacoBUZ();
            break;
        case 'B':
            //-...
            TracoBUZ();
            PontoBUZ();
            PontoBUZ();
            PontoBUZ();
            EspacoBUZ();
            break;
        case 'C':
            //-.-.
            TracoBUZ();
            PontoBUZ();
            TracoBUZ();
            PontoBUZ();
            EspacoBUZ();
            break;
        case 'D':
            //-..
            TracoBUZ();
            PontoBUZ();
            PontoBUZ();
            EspacoBUZ();
            break;
        case 'E':
            //.
            PontoBUZ();
            EspacoBUZ();
            break;
        case 'F':
            //..-.
            PontoBUZ();
            PontoBUZ();
            TracoBUZ();
            PontoBUZ();
            EspacoBUZ();
            break;
        case 'G':
            //--.
            TracoBUZ();
            TracoBUZ();
            PontoBUZ();
            EspacoBUZ();
            break;
        case 'H':
            //....
            PontoBUZ();
            PontoBUZ();
            PontoBUZ();
            PontoBUZ();
            EspacoBUZ();
            break;
        case 'I':
            //..
            PontoBUZ();
            PontoBUZ();
            EspacoBUZ();
            break;
        case 'J':
            //.---
            PontoBUZ();
            TracoBUZ();
            TracoBUZ();
            TracoBUZ();
            EspacoBUZ();
            break;
        case 'K':
            //-.-
            TracoBUZ();
            PontoBUZ();
            TracoBUZ();
            EspacoBUZ();
            break;
        case 'L':
            //.-..
            PontoBUZ();
            TracoBUZ();
            PontoBUZ();
            PontoBUZ();
            EspacoBUZ();
            break;
        case 'M':
            //--
            TracoBUZ();
            TracoBUZ();
            EspacoBUZ();
            break;
        case 'N':
            //-.
            TracoBUZ();
            PontoBUZ();
            EspacoBUZ();
            break;
        case 'O':
            //---
            TracoBUZ();
            TracoBUZ();
            TracoBUZ();
            EspacoBUZ();
            break;
        case 'P':
            //.--.
            PontoBUZ();
            TracoBUZ();
            TracoBUZ();
            PontoBUZ();
            EspacoBUZ();
            break;
        case 'Q':
            //--.-
            TracoBUZ();
            TracoBUZ();
            PontoBUZ();
            TracoBUZ();
            EspacoBUZ();
            break;
        case 'R':
            //.-.
            PontoBUZ();
            TracoBUZ();
            PontoBUZ();
            EspacoBUZ();
            break;
        case 'S':
            //...
            PontoBUZ();
            PontoBUZ();
            PontoBUZ();
            EspacoBUZ();
            break;
        case 'T':
            //-
            TracoBUZ();
            EspacoBUZ();
            break;
        case 'U':
            //..-
            PontoBUZ();
            PontoBUZ();
            TracoBUZ();
            EspacoBUZ();
            break;
        case 'V':
            //...-
            PontoBUZ();
            PontoBUZ();
            PontoBUZ();
            TracoBUZ();
            EspacoBUZ();
            break;
        case 'W':
            //.--
            PontoBUZ();
            TracoBUZ();
            TracoBUZ();
            EspacoBUZ();
            break;
        case 'X':
            //-..-
            TracoBUZ();
            PontoBUZ();
            PontoBUZ();
            TracoBUZ();
            EspacoBUZ();
            break;
        case 'Y':
            //-.--
            TracoBUZ();
            PontoBUZ();
            TracoBUZ();
            TracoBUZ();
            EspacoBUZ();
            break;
        case 'Z':
            //--..
            TracoBUZ();
            TracoBUZ();
            PontoBUZ();
            PontoBUZ();
            EspacoBUZ();
            break;
        default:
            gpio_put(led_pin, high);
            gpio_put(buzzer_b, high);
            break;
        }
};

void PontoBUZ()
{
    //Um Ponto(.) é representado pelo BUZ aceso por 0,2 segundos.
    tone(buzzer_b, 1000, 200);
    sleep_ms(125);
    printf(".");
}

void TracoBUZ()
{
    //Um traço(-) é representado pelo BUZ aceso por 0,8 segundos.
    tone(buzzer_b, 1000, 800);
    sleep_ms(125);
    printf("-");
}

void EspacoBUZ()
{
    //O intervalo entre letras deve ser de 0,25 segundos.
    sleep_ms(125);
}

void tone(uint gpio, uint freq, uint duration_ms) 
{
    uint period = 1000000 / freq;  // Período do sinal em microssegundos
    uint cycles = (duration_ms * 1000) / period;  // Número de ciclos a gerar

    for (uint i = 0; i < cycles; i++) {
        gpio_put(gpio, high);  // Liga o buzzer
        sleep_us(period / 2);  // Espera metade do período
        gpio_put(gpio, low);  // Desliga o buzzer
        sleep_us(period / 2);  // Espera metade do período
    }
}