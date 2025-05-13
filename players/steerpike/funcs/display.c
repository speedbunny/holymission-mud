string display(mixed var)
{
   if (intp(var))
      return "" + var;
   if (stringp(var))
      return sprintf("\"%s\"", var);
   if (objectp(var))
      return sprintf("%s [%s]",
         (string)var -> short() || (string)var -> query_name() || "<invisible>",
         file_name(var));
   if (pointerp(var))
      return sprintf("({%s})", implode(map_array(var, #'display), ","));
   if (mappingp(var))
   {
      string foo;
      mixed keys, values;
      int i;
      keys = m_indices(var);
      values = m_values(var);
      foo = "([";
      for (i = 0; i < sizeof(keys); i ++)
         foo = sprintf("%s%s:%s", foo, display(values[i]), display(keys[i]));
      return foo + "])";
   }
   return closurep(var) ? "<lambda closure>" : "<unknown type>";
}
