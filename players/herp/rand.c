get() { return 1; }
short() { return "true"; }
init() { add_action("test_random", "test"); }
test_random(str) {
   int i, a, b, s, k, iterations, range;

   if (sscanf(str, "%d %d", iterations, range) != 2) return 0;
   a = allocate(range);
   for (i = 0; i < iterations; i++) {
      a[random(range)]++;
      b++;
   }
   for (i = 0; i < range; i++) {
      write(i + "\t" + a[i] + "\t" + (a[i] * 100/iterations) + "%\n");
      s += a[i];
   }
   write("iterations: "+iterations+"\trange: "+range+"\tcount: "+b+
         "\tsum: "+s+"\n");
   return 1;
}
