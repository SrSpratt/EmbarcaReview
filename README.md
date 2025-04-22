# Embarcatech-Residência
## Embarca-Revisão
#### Autor:
* Roberto Vítor Lima Gomes Rodrigues

### Personagem enclausurado
Como projeto de revisão, para reaver contato com os conceitos de gpio, pio, interrupções, trepidação, pwm e conversão analógico-digital, foi implementado um pequeno cenário em que um personagem pode se mover, mas não pode encostar nas paredes do display (sendo os buzzers e LEDs vermelhos ligados quando ele faz isso).

#### Vídeo de funcionamento



#### Instruções de compilação
Certifique-se de que você tem o ambiente configurado conforme abaixo:
* Pico SDK instalado e configurado.
* VSCode com todas as extensões configuradas, CMake e Make instalados.
* Clone o repositório e abra a pasta do projeto, a extensão Pi Pico criará a pasta build
* Clique em Compile na barra inferior, do lado direito (ao lado esquerdo de RUN | PICO SDK)
* Verifique se gerou o arquivo .uf2
* Conecte a placa BitDogLab e ponha-a em modo BOOTSEL
* Arraste o arquivo até a placa, que o programa se iniciará

#### Manual do programa
Ao executar o programa, as seguintes características poderão ser verificadas:
* Os LEDs WS2812 se acenderão em azul juntamente ao display, indicando que uma "partida começou"
* Ao clicar em qualquer um dos três botões (A, B ou Joystick), a "partida começará" e os LEDs ficarão brancos, com um quadrado verde. O LED RGB também ficará verde.
* O usuário poderá se mover no espaço que não toca as paredes. Caso encoste nelas, o buzzer B tocará, e os LEDs mostrarão um X vermelho na tela. 
* O usuário deverá reiniciar clicando novamente em algum dos botões.
