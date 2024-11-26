## Ejemplo de uso

```c
#include <stdio.h>
#include <Light_Weight_Formatter.h>
#include <Light_Weight_Decoder.h>


// 1) Define una estructura que contenga todos los datos del mensaje que enviarás/recibirás (codificar y decodificar)
/typedef struct{ uint8_t u_byte;
    uint32_t u_4byte;
    float f;
    char * string;
    char * string_2;
    double d;
}IOT_Message;

// 2) Crea instancias de la estructura como si fuera un contenedor de mensajes
IOT_Message iot_message_decoded;//Crea un contenedor de mensajes con la estructura donde recibirás los datos
IOT_Message iot_message_encoder;//Crea un contenedor de mensajes con la estructura donde enviarás los datos

// 3) Crea el formateador o decodificador
Light_Weight_Formatter Specialized_Formatter;//Crea un Formateador desde donde enviarás los datos
Light_Weight_Decoder Lw_Decoder; //Crea un Decodificador desde donde recibirás los datos

int main(){

    //Inicializa el formateador
    LW_Formatter_Init(&Specialized_Formatter); //Initialize the formatter

    //Por comodidad, asigno variables a los miembros del formateador
    uint8_t * decoder_buffer_pointer = Specialized_Formatter.buffer;
    size_t decoder_buffer_size = Specialized_Formatter.elements;

    //Inicializa el decodificador
    LW_Decoder_Init(&Lw_Decoder, decoder_buffer_pointer, decoder_buffer_size);

    //Asigna valores a la estructura que tiene los datos que vas a codificar y luego enviar
    iot_message_encoder.u_byte = 123 + i*1000;
    iot_message_encoder.u_4byte = 4519871;
    iot_message_encoder.string = str;
    iot_message_encoder.d = 45133.645987;
    iot_message_encoder.f = 3.1415548794;
    iot_message_encoder.string_2 = str_2;

    printf("Encoding IOT Message...\r\n");
    //Lo mas importante aqui siempre sera codificar y decodificar en el mismo orden!
    //Ahora, reinicia el formateador y comienza a añadir los datos, segun el tipo que le corresponda a cada uno
    LW_Formatter_Restart(&Specialized_Formatter);
    LW_Formatter_Add_1_Byte_Unsigned(&Specialized_Formatter, iot_message_encoder.u_byte);
    LW_Formatter_Add_4_Byte_Unsigned(&Specialized_Formatter, iot_message_encoder.u_4byte);
    LW_Formatter_Add_Float(&Specialized_Formatter, iot_message_encoder.f);
    LW_Formatter_Add_Str(&Specialized_Formatter, iot_message_encoder.string, strlen(iot_message_encoder.string) + 1);//For Strings it is necesary to add strlen to the
    LW_Formatter_Add_Double(&Specialized_Formatter, iot_message_encoder.d);//string and + 1 to add the null character to the buffer
    LW_Formatter_Add_Str(&Specialized_Formatter, iot_message_encoder.string_2, strlen(iot_message_encoder.string_2) + 1); //Should it be hardcoded to the library?, you tell me :)

    //Para decodificar el mensaje, reinicia el decodificador y ocupa la estructura que almacenará los datos (ideal y normalmente siempre igual a la estructura de datos codificados) para guardar la informacion.
    LW_Decoder_Restart(&Lw_Decoder);
    iot_message_decoded.u_byte = LW_Decoder_Decode_1_Byte_Unsigned(&Lw_Decoder);
    iot_message_decoded.u_4byte = LW_Decoder_Decode_4_Byte_Unsigned(&Lw_Decoder);
    iot_message_decoded.f = LW_Decoder_Decode_Float(&Lw_Decoder);
    iot_message_decoded.string = LW_Decoder_Decode_String(&Lw_Decoder);
    iot_message_decoded.d = LW_Decoder_Decode_Double(&Lw_Decoder);
    iot_message_decoded.string_2 = LW_Decoder_Decode_String(&Lw_Decoder);

    return 0;
}
```

