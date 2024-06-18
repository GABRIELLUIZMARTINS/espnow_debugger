# ESP-NOW Debugger

Here we have the debugger implementation with the ESP-NOW protocol. There are two folders, one with the [espnow_receiver](espnow_receiver) module implementation and the other with the [espnow_sender](espnow_sender) module implementation.

In this case, it is possible to send three uint32_t numbers. But it is possible to change the amount of data sent to different applications. For this to be possible, you must have the same `Data_t` structure in the receiver and sender modules.

Firmware files are distributed as follows:

```pre
.
├── .vscode         # Visual Studio Code Workspace files
├── build           # Firmware build files (automatically generated)
└──  src            # Source code
    ├── main                            # Application example
    └── espnow_sender/espnow_receiver   # Implementation 
```

## ESP-NOW Receiver

To use the receiver module, initialize NVS, wifi and ESP-NOW. Then register the callback function for the received data, as in the [main.c](espnow_receiver/src/main/main.c) file.

## ESP-NOW Sender

To use the sender module, initialize NVS, wifi and ESP-NOW. Then, implement a task and use the `send_espnow()` function to transmit the data to the ESP receiver. The implementation example is avaliable in the [main.c](espnow_sender/src/main/main.c) file.

