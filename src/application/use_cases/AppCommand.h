#ifndef APPCOMMAND_H
#define APPCOMMAND_H

enum class AppCommand {
    StartClicking,
    StopClicking,
    ToggleRecording, // Futuro: Gravação de Macros
    PlaySequence,    // Futuro: Execução de Macros
    None
};

#endif // APPCOMMAND_H