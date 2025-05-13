/*
 * A test object for the printf() efun.
 */


#define SCREEN_WIDTH 79

init() {
  add_action("t1", "t1");
  add_action("t2", "t2");
  add_action("t3", "t3");
  add_action("t4", "t4");
  add_action("t5", "t5");
  add_action("t6", "t6");
  add_action("t7", "t7");
  add_action("t8", "t8");
  add_action("t9", "t9");
}

/*
 * An example of table mode ... ls
 * Defaults to / as no cwd is kept ...  It's just an example ...
 */
t1(str) {
  if (!str) str = "/";
  printf("%-*#s\n", SCREEN_WIDTH, implode(get_dir(str), "\n"));
  return 1;
}

/*
 * Some column mode examples ...
 */
t2() {
  printf("%-=*s\n", SCREEN_WIDTH, "The most obvious use of the column "+
         "mode is the fact that it wordwraps.  If you use it for room "+
         "descriptions, then one long line with no slosh-ns will print "+
         "a nicely wordwrapped output. If of course you want to force "+
         "a return, including a slosh-n will do just that.\nBut column "+
         "mode is more powerful than just that, the next statement "+
         "demonstrates some of the cute things you can do (note that "+
         "tables and columns are interchangable, whereever a column "+
         "is used, a table could just as easily be put in.)"
  );
  printf("A title: %-20=s  Another title: %-20=s\n",
         "Generating menus made easy :)  There are many cute things "+
         "that can be done this way, and printf() is only one eval "+
         "cost!  grin.",
         "Can you tell I hate making stupid test data?  And I'm not "+
         "even half way through the junk I should test/demonstrate."
  );
  return 1;
}

/*
 * %O
 */
t3() {
  printf("%-=*s\n", SCREEN_WIDTH, "This is only useful for testing, "+
         "but it is fairly useful for that!  Unfortuneately, I saw fit "+
         "to make it possible to do all the normal things you can do "+
         "with strings, with %O, ie: you can put it in columns (or "+
         "tables, god knows why...) etc, this means it's very slow, "+
         "when you start getting up around the 150+ element arrays "+
         "the pause is noticable..."
  );
  printf("%O\n", ({
            "You can use %O to print out any data type in LPC",
            SCREEN_WIDTH,
            this_player(),
            ({ "And arrays ARE data!  grin evilly." }),
         })
  );
  return 1;
}

/*
 * The pad string feature ...
 */
t4() {
  printf("%-=*s\n", SCREEN_WIDTH, "Another strange feature of this version is "+
         "the ability to specify the pad string, as Pinkfish calls "+
         "it, the fast way to draw a line...  One thing to note is "+
         "that it doesn't treat specified pad strings any different "+
         "from the default space padding, this means it won't put "+
         "trailing padding on unless it has to...  You can force it "+
         "to put trailing padding on by including slosh-ns in the "+
         "format string, or a space after the bit you want to force "+
         "the trailing padding on.\nNOTE: sloshs must be escaped past "+
         "the driver, so to include a single slosh in the pad string "+
         "requires 4 sloshes, and to include a ' requires 2 sloshes "+
         "followed by a single quote, this is the only place (in the "+
         "pad string specification) this double escaping is required "+
         "(in printf, at the current time)"
  );
  printf("%-'.'40s %4d\n", "Item", 40);
  printf("%-'.'40s%'.'5d\n", "Item", 40);
  printf("%|'-'*s\n", SCREEN_WIDTH, "==*==");
  printf("%|'\\\\'*s", SCREEN_WIDTH, "!\n");
  printf("%|'\\''*s\n", SCREEN_WIDTH, "!");
  return 1;
}

/*
 * Justification ...
 */
t5() {
  printf("%-=*s\n", SCREEN_WIDTH, "This version follows the default "+
         "of std printf() for justification, ie: right.  This is very "+
         "non-intuitive in a string based language...  shrug.  It also "+
         "has a centre justification."
  );
  printf("%-*s\n", SCREEN_WIDTH, "Left justified: -");
  printf("%|*s\n", SCREEN_WIDTH, "Centre justified: |");
  printf("%*s\n", SCREEN_WIDTH, "Right justified.");
  return 1;
}

/*
 * Array operator ...
 */
t6() {
  string *bing;
  int w;

  printf("%-=*s\n", SCREEN_WIDTH, "Another feature of dubious use "+
         "(I definately thought of many uses when I put it in!) "+
         "the array operator @ which applies the relevant section "+
         "of the format string "+
         "(minus the @ symbol, and no, two @'s is not recursive) "+
         "to each element of the array"
  );
  bing = ({
    "Several long strings columnarised?  shrug, well, it's here "+
    "if you ever find a need ;) ",
    "I can tell you are so happy, oh well, thought I better demo "+
    "it anyway, so the documentation was less obscure :)"
  });
  w = SCREEN_WIDTH/sizeof(bing);
  printf("%-=@*.*s\n", w, w-1, bing);
  return 1;
}

/*
 * Some numeric examples ...
 */
t7() {
  printf("num: %i\n", 10);
  printf("num: %10d\n", 10);
  printf("num: %|10d\n", 10);
  printf("num: %010d\n", 10);
  printf("num: %'x'10d\n", 10);
  printf("65 as int, hex, oct, and char: %d %X %o %c\n", 65, 65, 65, 65);
  return 1;
}

t8() {
  printf("There is no rule eight!\n");
  return 1;
}

/*
 * Run time error testing, designed for the version that returns/prints
 * the error messages, rather than error()ing...
 */
t9() {
  printf("%");
  printf("%*s");
  printf("%'", 80);
  printf("%s", 80);
  printf("%*s", "fish");
  printf("%#");
  printf("%:sgreen\n", "fish");
  printf("%5.sgreen\n", "fish");
  printf("%'\\'15s\n", "fish");
  return 1;
}
