#ifndef PARALELO_H
#define	PARALELO_H


#define MAX_THREADS 50

#ifdef	__cplusplus
extern "C" {
#endif

    struct thread_data{
        PersonList* menList;
        PersonList* womenList;
        FILE* file;
        int number;
        int satisfaction;
        PrefList* preflist;
        Person* person;
        PersonList* personList;
        
    };

    
struct thread_data thread_data_array[MAX_THREADS];    

#ifdef	__cplusplus
}
#endif

#endif	/* PARALELO_H */

