id(str) { return str == "map" || str == "old map"; }
short() { return "An old map"; }
get()	{ return 1; }
query_weight() { return 0; }
query_value() { return 300; }

long() {  
	int t;
	write("An old map: \n"); 
    write("[ ]-[ ]                                        \n");
    write(" |   | \\           Ye olde Labyrinth of Leaf VI\n");
    write("[ ]-[ ] [ ] [ ]                                \n");
    write("   \\   \\   x |                                 \n");
    write("    [ ] [ ] [ ] ( )-{Q}                        \n");
    write("       x   x   \\   \\                           \n");
    write("    [ ]-[ ] [ ] [ ] ( )-{Q}                    \n");
    write("           \\   \\ v \\   \\                       \n");
    write("        ( ) [ ]>[ ] [ ]-( )-{Q}                \n");
    write("         | \\   \\   \\       \\                   \n");
    write("        {Q} ( ) [ ] [ ] [ ] ( )-{Q}            \n");
    write("             | \\ |  .  x   \\   \\               \n");
    write("            {Q} ( ) [ ]-[ ] [ ] ( )-{Q}        \n");
    write("                 | \\    ,  / |                 \n");
    write("                {Q} ( ) [ ] [ ] [ ]-[ ]        \n");
    write("                     | \\   \\   x       \\       \n");
    write("                    {Q} ( ) [ ] [ ]-[ ] 108    \n");
    write("    > : one-way          |     /     | x       \n");
    write("    . : from            {Q} [ ] [ ]-[ ] [ ]    \n");
    write("    , : to                     \\   x   \\   \\   \n");
    write("    .. : press shield           [ ] [ ] [G] [ ]\n");
    write("    G : griffin!                       \\   x ..\n");
    write("    C : circular hall/2 shields         [ ]:(C)\n");
}

