reset(arg)
{ 
   string str, a;
   int b, c;
   if (arg) return;
   str = read_file("/players/steerpike/map");
   while (sscanf(str, "%d: %s\n%s", b, a, c, str) == 4)
   {
      b += 11;
      switch (b)
      {
	 case 55: c = 0; break;
	 case 25:
	 case 52:
	 case 58:
	 case 85: c = 1; break;
	 case 33:
	 case 37:
	 case 77:
	 case 73: c = 2; break;
	 default: c = 3 + random(4); break;
      }
      write_file("/players/steerpike/map2", sprintf("%d: %s %d\n", a, b, c));
   }
}
