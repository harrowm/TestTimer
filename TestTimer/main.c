//
//  main.c
//  TestTimer
//
//  Created by Malcolm on 31/12/14.
//

#include <stdio.h>
#include <allegro.h>

int main(int argc, char **argv)
{
    ALLEGRO_EVENT_QUEUE *events;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer;
    
    int quited = 0;
    int counter = 1;
    
    if (!al_init())
    {
        printf("Can't initialize Allegro - quiting!\n");
        return (1);
    }
    
    timer = al_create_timer(1.0/5);
    if (timer == NULL)
    {
        printf("Error creating Allegro timer\n");
        return(1);
    }
    
    events = al_create_event_queue();
    if (events == NULL)
    {
        printf("Error creating Allegro event queue\n");
        return (1);
    }
    
    al_register_event_source(events, al_get_timer_event_source(timer));
    al_start_timer(timer);

    while (!quited)
    {
        if (counter == 6)
        {
            al_destroy_timer(timer);
            timer = al_create_timer(1.0);
            if (timer == NULL)
            {
                printf("Error creating Allegro timer\n");
                return (1);
            }
            al_register_event_source(events, al_get_timer_event_source(timer));
            al_start_timer(timer);
            printf("\n");
        }
        
        if (counter == 15)
        {
            al_set_timer_speed(timer, 1.0/5);
            printf("\n");
        }
        
        al_wait_for_event(events, &event);
        switch (event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                printf("%d ", counter++);
                break;
        }
        
        if (counter == 16) quited = true;
    }
    return (0);
}

