inherit "obj/thing";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "tester" );
  set_short( "A tester" );
  set_long( "A tester.\n" );
}

void init() {
  ::init();
  add_action( "do_test", "test" );
}

int do_test() {
  string str, sub1, sub2;

  str = "abcdefghij";
  sub1 = extract( str, 3, 6 );
  sub2 = str[3..6];
  printf( "sub1 = %s\nsub2 = %s\n", sub1, sub2 );
  sub1[0] = 'z';
  sub2[0] = 'y';
  printf( "str = %s\nsub1 = %s\nsub2 = %s\n", str, sub1, sub2 );
  return 1;
}
