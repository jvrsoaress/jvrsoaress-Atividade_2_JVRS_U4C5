<img width=100% src="https://capsule-render.vercel.app/api?type=waving&color=02A6F4&height=120&section=header"/>
<h1 align="center">Embarcatech Atividade 2 - U4C5 </h1>

## Objetivo do Projeto

Este projeto implementa um sistema de temporização para acionamento de LEDs utilizando um Raspberry Pi Pico W. O sistema é ativado por um botão (pushbutton) e desliga os LEDs sequencialmente a cada 3 segundos, conforme os requisitos da atividade. O projeto foi desenvolvido como parte de uma atividade prática que exigia o uso da função add_alarm_in_ms() do Pico SDK para criar um temporizador de um disparo (one-shot) e controlar a mudança de estados dos LEDs.

## 🗒️ Lista de requisitos

- **Uso de interrupções**: Todas as funcionalidades relacionadas aos botões devem ser implementadas utilizando rotinas de interrupção (IRQ); 
- **Debouncing**: É obrigatório implementar o tratamento do bouncing dos botões via software; 
- **Controle de LEDs**: O projeto deve incluir o uso de LEDs comuns e LEDs WS2812, demonstrando o domínio de diferentes tipos de controle;
- **Organização do código**: O código deve estar bem estruturado e comentado para facilitar o entendimento.

## 🛠 Tecnologias

- **Microcontrolador:** Raspberry Pi Pico W  
- **LEDs:** RGB (Vermelho, Verde, Azul)  
  - 1x LED Vermelho  
  - 1x LED Azul (substituindo o amarelo do semáforo)
  - 1x LED Verde  
- **Resistores:** 3x Resistores de 330 Ω  
- **Ferramenta de Simulação:** Wokwi  
- **Linguagem de Programação:** C  
- **Frameworks:** Pico SDK


## 🔧 Funcionalidades Implementadas:

1. **Acionamento por botão:** O sistema é ativado ao pressionar o botão, ligando todos os LEDs.
2. **Desligamento sequencial:** Após 3 segundos, os LEDs são desligados um por um, com intervalo de 3 segundos entre cada desligamento.
3. **Bloqueio de acionamento:** O botão só pode ser pressionado novamente após todos os LEDs serem desligados.
4. **Debounce simples:** Implementação de um debounce básico para evitar leituras falsas do botão.

## 🚀 Passos para Compilação e Upload  

1. **Clonar o repositório** 

- sh
- git clone seu repositorio
- cd semaforo-pico


2. **Configurar e compilar o projeto**  

`mkdir build && cd build`
`cmake ..`
`make`

3. **Transferir o firmware para a placa**

- Conectar a placa BitDogLab ao computador
- Copiar o arquivo .uf2 gerado para o drive da placa

4. **Testar o projeto**

🛠🔧🛠🔧🛠🔧


## 💻 Desenvolvedor
 
<table>
  <tr>
    <td align="center"><img style="" src="https://avatars.githubusercontent.com/u/191687774?v=4" width="100px;" alt=""/><br /><sub><b> José Vinicius </b></sub></a><br />👨‍💻</a></td>
  </tr>
</table>
