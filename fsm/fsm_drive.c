drive and idle states for an fsm

//Events
typedef enum
{
    STOP,
    START
} EVENT

//States
typedef enum
{
    IDLE,
    DRIVE
} STATE


enum STATE state;


void idleStateHandler(EVENT input)
{
    if(input == STOP)
    {
        state = IDLE;
        //no change
    }
    else if (input == START)
    {
        state = DRIVE;
        //Change
    }
}

void driveStateHandler(EVENT input)
{
    if(input == STOP)
    {
        state = IDLE;
        //CHANGE
    }
    else if (input == START)
    {
        state = DRIVE;
        //NO change
    }
}

void StateMachineHandler(EVENT input)
{
    switch(state)
    {
        case IDLE:
            printf("IDLE STATE");
            idleStateHandler(input);
            break;
        case DRIVE:
            printf("Drive State");
            driveStateHandler(input);
            break;
        default:
            break;
    }
}

int main()
{
    state = IDLE;
    EVENT input = STOP;
    int i = 64;
    while(i > 0)
    {
        if (i % 2)
        {
            input = START;
        }
        else{
            input = STOP;
        }
        i--;
    }
return 0;
}