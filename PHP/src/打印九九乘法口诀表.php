<?PHP
  echo '打印九九乘法口诀表';
  echo '<br \>';

  for($i = 1; $i <= 9; $i++)
  {
    for($j = 1; $j <= 9; $j++)
    {
      echo $j, '*', $i, '=', $i*$j, '  ';
      if($j == $i)
      {
        echo '<br \>';
        break;
      }
    }
  }

?>


<!--  
1*1
1*2 2*2
1*3 2*3 3*3
1*4 2*4 3*4 4*4

i*j
i*j i*j
i*j i*j i*j
i*j i*j i*j i*j
-->