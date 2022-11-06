#define LED_BEHAVIOUR_DIGITAL_STATIC 1
#define LED_BEHAVIOUR_DIGITAL_VARIABLE 2
#define LED_BEHAVIOUR_PWM_STATIC 3
#define LED_BEHAVIOUR_PWM_VARIABLE 4

//Choose one LED_BEHAVIOUR ONLY
//#define LED_BEHAVIOUR LED_BEHAVIOUR_DIGITAL_STATIC
//#define LED_BEHAVIOUR LED_BEHAVIOUR_DIGITAL_VARIABLE
//#define LED_BEHAVIOUR LED_BEHAVIOUR_PWM_STATIC
#define LED_BEHAVIOUR LED_BEHAVIOUR_PWM_VARIABLE

#define LED_PIN 4
#define LED_NEGATIVE_LOGIC false

// #define CONTACT_PIN 5
// #define CONTACT_NEGATIVE_LOGIC true
// #define INTERNAL_PULLUP true
// #define DEBOUNCE_INTERVAL 200 //during this interval after a change of input state, any subsequent changes will be ignores. After the interval the state will be reevaluated and a new state change might be fired.

// #define SERIAL_SPEED 19200