/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


$(function(){
   $("#middle").hide().slideDown(2000); 

   //html tag
   $('#html').mouseenter(function(){
       $('#html').css("color",'red');
   });
   $('#html').mouseleave(function(){
       $('#html').css("color",'black');
   });
   
   //css tag
   $('#css').mouseenter(function(){
       $('#css').css("color",'red');
   });
   $('#css').mouseleave(function(){
       $('#css').css("color",'black');
   });
   
   //js tag
   $('#JS').mouseenter(function(){
       $('#JS').css("color",'red');
   });
   $('#JS').mouseleave(function(){
       $('#JS').css("color",'black');
   });
   
    //w3 tag
   $('#W3').mouseenter(function(){
       $('#W3').css("color",'red');
   });
   $('#W3').mouseleave(function(){
       $('#W3').css("color",'black');
   });
   
   //php
   $('#php').mouseenter(function(){
       $('#php').css("color",'red');
   });
   $('#php').mouseleave(function(){
       $('#php').css("color",'black');
   });
   
   //ajax for the school summary
   $('#school1').click(function(){
       $.post("php.php",{school:"snhu"}).done(function(data){
           $('#summary').html(data);
       });
   });
   
   $('#school2').click(function(){
      $.post("php.php",{school:"regis"}).done(function(data){
         $('#summary').html(data); 
      }); 
   });
   
   $('#school3').click(function(){
      $.post("php.php",{school:"lonestar"}).done(function(data){
         $('#summary').html(data); 
      }); 
   });
});