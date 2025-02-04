#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

// Definindo os pinos dos LEDs e do botão
const uint LED_BLUE_PIN = 12;   // LED Azul no GPIO 12
const uint LED_RED_PIN = 13;    // LED Vermelho no GPIO 13
const uint LED_GREEN_PIN = 11;  // LED Verde no GPIO 11
const uint BUTTON_PIN = 5;      // Botão no GPIO 5

// Variáveis de estado
bool leds_active = false;       // Indica se os LEDs estão ativos
int led_state = 0;              // Controla o estado atual dos LEDs

// Função de callback para desligar os LEDs após 3 segundos
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    switch (led_state) {
        case 0:
            gpio_put(LED_RED_PIN, false); // Desliga o LED vermelho primeiro
            led_state = 1;
            break;
        case 1:
            gpio_put(LED_BLUE_PIN, false); // Depois, desliga o LED azul
            led_state = 2;
            break;
        case 2:
            gpio_put(LED_GREEN_PIN, false); // Por último, desliga o LED verde
            leds_active = false;  // Finaliza a sequência
            led_state = 0;        // Reseta o estado
            return 0; // Último desligamento, sem novo alarme
    }

    // Agenda outro alarme para continuar a sequência
    add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    return 0;
}

int main() {
    stdio_init_all();

    // Configura os pinos dos LEDs como saída
    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

    // Configura o pino do botão como entrada com pull-up
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    // Loop principal
    while (true) {
        if (gpio_get(BUTTON_PIN) == 0 && !leds_active) {
            sleep_ms(50); // Debounce
            if (gpio_get(BUTTON_PIN) == 0) {
                // Liga todos os LEDs
                gpio_put(LED_BLUE_PIN, true);
                gpio_put(LED_RED_PIN, true);
                gpio_put(LED_GREEN_PIN, true);

                // Atualiza o estado
                leds_active = true;
                led_state = 0;

                // Inicia a sequência de desligamento
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }
        sleep_ms(10);
    }

    return 0;
}
