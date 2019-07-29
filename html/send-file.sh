#!/bin/bash

# Envia o arquivo
curl -v -F 'var1=val1' -F 'snd=@../audio/a2002011001-e02-8kHz.wav' 127.0.0.1:1234/soundInput

# Para o servidor
# curl -v 127.0.0.1:1234/stop

# Compara o que foi enviado com o que foi salvo
diff ../audio/a2002011001-e02-8kHz.wav ../src/audio-recebido.wav
