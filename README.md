# vapore-servo
Programma in arduino per il controllo di una pompa che alimenta un generatore di vapore e un servo motore che controlla un piatto che può salire o scendere sopra ad il vapore per mostrare la condensa.

## setup
 - installare arduino IDE da qui: arduino.cc
 - collegare il cavo usb al pc
 - impostare come scheda ARDUINO/GENUINO UNO
 - scegliere la giusta porta USB tra quelle in elenco
 - dal menu "Sketch" andare su #include libreria e poi cliccare su "Gestione Librerie..."
 - verificare di avere installate o installare le seguenti librerie:
 	- servo
 	- fastLED

## modificare il software
All'interno del ciclo LOOP ci sono in chiaro e commentati tutti i valori da cambiare per modificare i movimenti e i tempi.
