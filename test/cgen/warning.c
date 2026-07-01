#include "meta/cgen/micros.h"
#include "meta/cgen/warning.h"

CTEST_MAIN(meta_cgen: warning);

    // Reset counter for consistent testing
    cwarningCounter = 0;
    
    // Test 1: cwarning_init() - Initialize warning with default values
    cwarning w1 = cwarning_init();
    CTEST_EQU(w1.name == NULL, true);                    // name should be NULL
    CTEST_EQU(w1.description == NULL, true);             // description should be NULL
    CTEST_EQU(w1.file == NULL, true);                    // file should be NULL
    CTEST_EQU(w1.time == NULL, true);                    // time should be NULL
    CTEST_EQU(w1.line, 0);                               // line should be 0
    CTEST_EQU(w1.number, 0);                             // number should be 0 (first init)
    
    // Test 2: Counter increments after init
    size_t counter_before = cwarningCounter;
    cwarning w2 = cwarning_init();
    CTEST_EQU(w2.number, counter_before);                // number should match counter
    CTEST_EQU(cwarningCounter, counter_before + 1);      // counter should increment
    
    // Test 3: wrong_indexing() - Create wrong indexing warning
    size_t counter_start = cwarningCounter;
    cwarning w_index = wrong_indexing("Array boundary check");
    CTEST_EQU(w_index.name != NULL, true);               // name should not be NULL
    CTEST_EQU(strcmp(w_index.name, "Wrong Indexing"), 0);    // verify name
    CTEST_EQU(w_index.description != NULL, true);        // description should not be NULL
    CTEST_EQU(strcmp(w_index.description, "Array boundary check"), 0);  // verify description
    CTEST_EQU(w_index.file != NULL, true);               // file should be set
    CTEST_EQU(w_index.time != NULL, true);               // time should be set
    CTEST_ASSERT(w_index.line > 0);                    // line should be set (> 0)
    CTEST_EQU(w_index.number, counter_start);            // number should match counter
    CTEST_EQU(cwarningCounter, counter_start + 1);       // counter should increment
    
    // Test 4: wrong_declaration() - Create wrong declaration warning
    counter_before = cwarningCounter;
    cwarning w_decl = wrong_declaration("Unused variable");
    CTEST_EQU(w_decl.name != NULL, true);                // name should not be NULL
    CTEST_EQU(strcmp(w_decl.name, "Wrong declaration"), 0);   // verify name
    CTEST_EQU(w_decl.description != NULL, true);         // description should not be NULL
    CTEST_EQU(strcmp(w_decl.description, "Unused variable"), 0);  // verify description
    CTEST_EQU(w_decl.number, counter_before);            // verify counter
    CTEST_EQU(cwarningCounter, counter_before + 1);      // counter incremented
    
    // Test 5: wrong_construction() - Create wrong construction warning
    counter_before = cwarningCounter;
    cwarning w_cons = wrong_construction("Incomplete initialization");
    CTEST_EQU(w_cons.name != NULL, true);                // name should not be NULL
    CTEST_EQU(strcmp(w_cons.name, "Wrong Construction"), 0);   // verify name
    CTEST_EQU(w_cons.description != NULL, true);         // description should not be NULL
    CTEST_EQU(w_cons.number, counter_before);            // verify counter
    
    // Test 6: bad_input() - Create bad input warning
    counter_before = cwarningCounter;
    cwarning w_input = bad_input("Suspicious value detected");
    CTEST_EQU(w_input.name != NULL, true);               // name should not be NULL
    CTEST_EQU(strcmp(w_input.name, "Bad Input"), 0);     // verify name
    CTEST_EQU(w_input.description != NULL, true);        // description should not be NULL
    CTEST_EQU(w_input.number, counter_before);           // verify counter incremented
    
    // Test 7: undefined_behavior() - Create undefined behavior warning
    counter_before = cwarningCounter;
    cwarning w_undef = undefined_behavior("Potential memory issue");
    CTEST_EQU(w_undef.name != NULL, true);               // name should not be NULL
    CTEST_EQU(strcmp(w_undef.name, "Undefined Behavior"), 0);  // verify name
    CTEST_EQU(w_undef.description != NULL, true);        // description should not be NULL
    CTEST_EQU(w_undef.number, counter_before);           // verify counter
    
    // Test 8: invalid_argument() - Create invalid argument warning
    counter_before = cwarningCounter;
    cwarning w_arg = invalid_argument("Type mismatch warning");
    CTEST_EQU(w_arg.name != NULL, true);                 // name should not be NULL
    CTEST_EQU(strcmp(w_arg.name, "Invalid Argument"), 0);     // verify name
    CTEST_EQU(w_arg.description != NULL, true);          // description should not be NULL
    CTEST_EQU(w_arg.number, counter_before);             // verify counter incremented
    
    // Test 9: Sequential warnings have unique numbers
    cwarningCounter = 100;  // Set custom start
    cwarning seq1 = wrong_indexing("First");
    cwarning seq2 = bad_input("Second");
    cwarning seq3 = invalid_argument("Third");
    CTEST_EQU(seq1.number, 100);                         // first number
    CTEST_EQU(seq2.number, 101);                         // second number (incremented)
    CTEST_EQU(seq3.number, 102);                         // third number (incremented)
    CTEST_EQU(cwarningCounter, 103);                     // counter at 103
    
    // Test 10: Warning with empty description
    counter_before = cwarningCounter;
    cwarning w_empty = bad_input("");
    CTEST_EQU(w_empty.name != NULL, true);               // name should not be NULL
    CTEST_EQU(w_empty.description != NULL, true);        // description initialized
    CTEST_EQU(strlen(w_empty.description), 0);           // should be empty
    CTEST_EQU(w_empty.number, counter_before);           // number properly set
    
    // Test 11: All warning creators preserve name correctly
    cwarning wt1 = wrong_indexing("test");
    cwarning wt2 = wrong_declaration("test");
    cwarning wt3 = wrong_construction("test");
    cwarning wt4 = bad_input("test");
    cwarning wt5 = undefined_behavior("test");
    cwarning wt6 = invalid_argument("test");
    CTEST_ASSERT(wt1.name != NULL && strlen(wt1.name) > 0);  // all names set
    CTEST_ASSERT(wt2.name != NULL && strlen(wt2.name) > 0);
    CTEST_ASSERT(wt3.name != NULL && strlen(wt3.name) > 0);
    CTEST_ASSERT(wt4.name != NULL && strlen(wt4.name) > 0);
    CTEST_ASSERT(wt5.name != NULL && strlen(wt5.name) > 0);
    CTEST_ASSERT(wt6.name != NULL && strlen(wt6.name) > 0);
    
    // Test 12: All warnings properly initialized
    CTEST_EQU(wt1.number < wt2.number, true);            // numbers incrementing
    CTEST_EQU(wt2.number < wt3.number, true);
    CTEST_EQU(wt3.number < wt4.number, true);
    CTEST_EQU(wt4.number < wt5.number, true);
    CTEST_EQU(wt5.number < wt6.number, true);

CTEST_EXIT(true)