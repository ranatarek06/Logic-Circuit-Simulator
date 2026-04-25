#ifndef CONST_H
#define CONST_H

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

// All possible operations in the application
enum ActionType
{
    // Add gates
    ADD_AND_GATE_2,
    ADD_OR_GATE_2,
    ADD_NAND_GATE_2,
    ADD_NOR_GATE_2,
    ADD_XOR_GATE_2,
    ADD_XNOR_GATE_2,

    ADD_AND_GATE_3,
    ADD_NOR_GATE_3,
    ADD_XOR_GATE_3,

    // Add single-input gates
    ADD_BUF,
    ADD_INV,

    // Add components
    ADD_SWITCH,
    ADD_LED,
    ADD_CONNECTION,

    // Editing operations
    COPY,
    CUT,
    PASTE,
    SAVE,
    MOVE,
    DEL,
    MUL,
    SEL,
    UNSEL,

    // Modes
    SIM_MODE,
    DSN_MODE,

    // Simulation-related actions
    CVALID,
    SIMC,
    TTB,
    CPR,

    // Labels
    LABEL,
    ADD_Label,
    EDIT_LABEL,

    // Circuit I/O
    Create_TruthTable,
    Change_Switch,
    LOAD,

    // Undo / Redo
    UNDO,
    REDO,

    // App Exit
    EXIT,


    // UI Click events
    STATUS_BAR,
    DSN_TOOL
};

// Possible states of a pin
enum STATUS
{
    LOW,
    HIGH
};

// Operating modes
enum MODE
{
    DESIGN,
    SIMULATION
};

// Items in design menu
enum DsgnMenuItem
{
    ITM_AND2,
    ITM_OR2,
    ITM_NAND2,
    ITM_NOR2,
    ITM_XOR2,
    ITM_XNOR2,

    ITM_AND3,
    ITM_NOR3,
    ITM_XOR3,

    ITM_SWITCH,
    ITM_LED,
    ITM_BUF,
    ITM_INV,
    ITM_CNC,

    ITM_COPY,
    ITM_CUT,
    ITM_PASTE,

    ITM_SAVE,
    ITM_MOVE,
    ITM_DEL,
    ITM_MUL,
    ITM_SEL,
    ITM_UNSEL,
    ITM_LABEL,
    ITM_EDITLABEL,
    ITM_LOAD,
    ITM_REDO,
    ITM_UNDO,

    ITM_SIM_MODE,
    ITM_EXIT,
    ITM_EMPTY_D,


    //ITM_DSNTOOL,
    //ITM_STATUSBAR,


    ITM_DSN_CNT      // must stay last
};

// Items in simulation menu
enum SimMenuItem
{
    ITM_SIMC,
    ITM_TTB,
    ITM_CPR,
    ITM_CVALID,
    ITM_DSN_MODE,
    ITM_EXIT_S,
    ITM_EMPTY_S,

    ITM_SIM_CNT      // must stay last
};

// Max number of output fanouts
constexpr int MAX_CONNS = 20;

// Default fan-out of 2-input AND gate
enum FANOUT
{
    AND2_FANOUT = 5,
    OR2_FANOUT = 5,
    NAND2_FANOUT = 5,
    NOR2_FANOUT = 5,
    XOR2_FANOUT = 5,
    XNOR2_FANOUT = 5,
    AND3_FANOUT = 5,
    NOR3_FANOUT = 5,
    XOR3_FANOUT = 5,
    BUF_FANOUT = 5,
    INV_FANOUT = 5,
    SWITCH_FANOUT = 5,
    LED_FANOUT = 5

};

// For drawing components (rectangular region)
struct GraphicsInfo
{
    int x1, y1;   // Top-left
    int x2, y2;   // Bottom-right
};

constexpr int GRAPHICS_NULL = 0;

#endif