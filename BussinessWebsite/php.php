<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

if($_SERVER["REQUEST_METHOD"] == "POST")
{
    //assign vars after formatting to avoid a wrong login with correct 
    //username and password
    $school = trim($_POST["school"]);
    
    //specfic message
    $lonestar = "Lone Star college is a two year college located in Houston,TX."
              . "  Lone Star offers a large variaty of Assocaties's degrees, "
              . "and is one of the largest two year colleges in Texas."
              ."  I earned a Assocaties of Arts in 2012 from Lone Star.";
    
   $snhu = "Southern New Hampshire University or SNHU is a private, non-profit "
           ."university located in Manchester and Hooksett New Hampshire that was founded in 1932.  "
           ."  SNHU offers many online Associate's, Bachelor's, and Masters' degrees. "
           ."  I earned a Bachelor's degree in Mathematics in 2016 with a 3.0 GPA";
   
   $regis = "Regis is a private, Jesuit university. Currently, Regis is one of only "
           . "28 Jesuit colleges in the United States.  Founded in 1877 by a group of "
           . "exiled Italian Jesuites under the name Las Vegas College, it was later "
           . "named College of the Sacred Heart in 1887 and moved to it's current location"
           . " Denver, Colorado.  Currently, Regis offers many remote degrees.  As of now, I am"
           . " working on a M.S in Software engineering with a concentration in web develoopment "
           . " I have a 4.0 GPA and I am expected to graduate in May of 2018";
    
   //select message to display
    if($school == "lonestar")
    {
        include("html.html");
        echo('<message>'.$lonestar.'</message>');
    }
    
    if($school == "snhu")
    {
        include("html.html");
        echo('<message>'.$snhu.'</message>');
    }
    
    if($school == "regis")
    {
        include("html.html");
        echo('<message>'.$regis.'</message>');
    }
    
    
    
}
