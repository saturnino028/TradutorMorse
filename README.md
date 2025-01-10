# Projeto: SOS em Código Morse com LED e Buzzer

## Descrição
Este projeto utiliza um LED e um buzzer conectados a um microcontrolador para transmitir o sinal **SOS** em Código Morse, tanto de forma luminosa quanto sonora.  
O sistema segue as regras do Código Morse, respeitando intervalos de tempo específicos para pontos, traços e espaçamentos.

## Funcionalidades
- **Sinal Luminoso (LED)**: Transmite o código Morse utilizando um LED conectado à GPIO.
- **Sinal Sonoro (Buzzer)**: Reproduz o código Morse emitindo sons através de um buzzer.
- Ciclo repetitivo do sinal SOS:
  - Três pontos (`...`)
  - Três traços (`---`)
  - Três pontos (`...`)
  - Intervalo de 3 segundos antes de reiniciar o ciclo.

## Regras de Operação
- Um ponto (`.`) é representado por:
  - LED ou buzzer ativo por **0,2 segundos**.
- Um traço (`-`) é representado por:
  - LED ou buzzer ativo por **0,8 segundos**.
- Intervalos:
  - Entre pontos e traços na mesma letra: **0,125 segundos**.
  - Entre letras: **0,25 segundos**.
  - Entre ciclos do SOS: **3 segundos**.

## Componentes
1. **Microcontrolador**: RP2040 (Raspberry Pi Pico).
2. **LED Externo**: Conectado ao pino GPIO **13**.
3. **Buzzer**: Conectado ao pino GPIO **10**.

## Configuração do Hardware
| Componente | GPIO | Função            |
|------------|------|-------------------|
| LED        | 13   | Emissão luminosa  |
| Buzzer     | 10   | Emissão sonora    |

## Requisitos
- **Software**:
  - [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk)
  - Compilador C (ex.: GCC).
- **Bibliotecas**:
  - `pico/stdlib.h` para controle GPIO e temporização.

## Como Usar
1. **Clone o repositório do projeto:**
   
   git clone https://github.com/saturnino028/TradutorMorse.git
   
3. **Import o projeto usando a extensão do Raspberry Pi Pico:**
   
   clique em import project e selecione o diretorio que foi clonado
   
3.**Compile o código**

4.**Se tiver com todas as extensões instaladas (Wokwi), basta clicar no diagram.json**
