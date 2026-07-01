#include "meta/cgen/micros.h"
#include "meta/cgen/error.h"

CTEST_MAIN(meta_cgen: error);

    // Test 1: errInit() - Initialize error with default values
    cerror err1 = errInit();
    CTEST_EQU(err1.name == NULL, true); // name should be NULL
    CTEST_EQU(err1.description == NULL, true); // description should be NULL
    CTEST_EQU(err1.file == NULL, true); // file should be NULL
    CTEST_EQU(err1.time == NULL, true); // time should be NULL
    CTEST_EQU(err1.line, 0); // line should be 0
    
    // Test 2: errIndexing() - Create wrong indexing error
    cerror err_index = errIndexing("Array out of bounds");
    CTEST_EQU(err_index.name != NULL, true); // name should not be NULL
    CTEST_EQU(strcmp(err_index.name, "Wrong Indexing"), 0); // name should be "Wrong Indexing"
    CTEST_EQU(err_index.description != NULL, true); // description should not be NULL
    CTEST_EQU(strcmp(err_index.description, "Array out of bounds"), 0); // verify description
    CTEST_EQU(err_index.file != NULL, true); // file should be set
    CTEST_EQU(err_index.time != NULL, true); // time should be set
    CTEST_ASSERT(err_index.line > 0); // line should be set (> 0)
    
    // Test 3: errDeclaration() - Create wrong declaration error
    cerror err_decl = errDeclaration("Invalid variable type");
    CTEST_EQU(err_decl.name != NULL, true); // name should not be NULL
    CTEST_EQU(strcmp(err_decl.name, "Wrong declaration"), 0); // verify name
    CTEST_EQU(err_decl.description != NULL, true); // description should not be NULL
    CTEST_EQU(strcmp(err_decl.description, "Invalid variable type"), 0); // verify description
    
    // Test 4: errConstruction() - Create wrong construction error
    cerror err_cons = errConstruction("Struct member missing");
    CTEST_EQU(err_cons.name != NULL, true); // name should not be NULL
    CTEST_EQU(strcmp(err_cons.name, "Wrong Construction"), 0); // verify name
    CTEST_EQU(err_cons.description != NULL, true); // description should not be NULL
    
    // Test 5: errBadInput() - Create bad input error
    cerror err_input = errBadInput("Invalid parameter value");
    CTEST_EQU(err_input.name != NULL, true); // name should not be NULL
    CTEST_EQU(strcmp(err_input.name, "Bad Input"), 0); // verify name
    CTEST_EQU(err_input.description != NULL, true); // description should not be NULL
    
    // Test 6: errUndefinedBehavior() - Create undefined behavior error
    cerror err_undef = errUndefinedBehavior("NULL pointer dereference");
    CTEST_EQU(err_undef.name != NULL, true); // name should not be NULL
    CTEST_EQU(strcmp(err_undef.name, "Undefined Behavior"), 0); // verify name
    CTEST_EQU(err_undef.description != NULL, true); // description should not be NULL
    
    // Test 7: errInvalidArgument() - Create invalid argument error
    cerror err_arg = errInvalidArgument("Argument count mismatch");
    CTEST_EQU(err_arg.name != NULL, true); // name should not be NULL
    CTEST_EQU(strcmp(err_arg.name, "Invalid Argument"), 0); // verify name
    CTEST_EQU(err_arg.description != NULL, true); // description should not be NULL
    
    // Test 8: Multiple errors with different descriptions
    cerror err_multi1 = errIndexing("First error");
    cerror err_multi2 = errIndexing("Second error");
    CTEST_EQU(strcmp(err_multi1.description, "First error"), 0);   // verify first
    CTEST_EQU(strcmp(err_multi2.description, "Second error"), 0);  // verify second
    CTEST_EQU(strcmp(err_multi1.name, err_multi2.name), 0);         // both have same name
    
    // Test 9: Error with empty string description
    cerror err_empty = errBadInput("");
    CTEST_EQU(err_empty.name != NULL, true);             // name should not be NULL
    CTEST_EQU(err_empty.description != NULL, true);      // description initialized (empty string)
    CTEST_EQU(strlen(err_empty.description), 0);         // should be empty
    
    // Test 10: All error creators preserve name correctly
    cerror e1 = errIndexing("test");
    cerror e2 = errDeclaration("test");
    cerror e3 = errConstruction("test");
    cerror e4 = errBadInput("test");
    cerror e5 = errUndefinedBehavior("test");
    cerror e6 = errInvalidArgument("test");
    CTEST_ASSERT(e1.name != NULL && strlen(e1.name) > 0); // all names set
    CTEST_ASSERT(e2.name != NULL && strlen(e2.name) > 0);
    CTEST_ASSERT(e3.name != NULL && strlen(e3.name) > 0);
    CTEST_ASSERT(e4.name != NULL && strlen(e4.name) > 0);
    CTEST_ASSERT(e5.name != NULL && strlen(e5.name) > 0);
    CTEST_ASSERT(e6.name != NULL && strlen(e6.name) > 0);

CTEST_EXIT(true)