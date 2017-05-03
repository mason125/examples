/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


function myMap() {
    var myCenter = new google.maps.LatLng(29.667418,-95.049149);//center of map
    var monumentLoc = new google.maps.LatLng(29.74972, -95.08056);//monumet location 
    var mapCanvas = document.getElementById("map");//map canvas
    
    var styles = [//sytles
                  {
                    featureType: "landscape",
                    stylers: [
                            { color: '#85f300' }
                    ]
            },{
                    featureType: "natural",
                    stylers: [
                            { hue: '#ff0000' }
                    ]
            },{
                    featureType: "road",
                    stylers: [
                            { hue: '#5500aa' },
                            { saturation: -100 }
                    ]
            },{
                    featureType: "building",
                    elementType: "labels",
                    stylers: [
                            { hue: '#000066' }
                    ]
            }
    ];
  
    var mapOptions = {
      center: myCenter,
      mapTypeId: google.maps.MapTypeId.TERRAIN,
      zoom: 9,
      styles: styles
    };
    
    //markers 
    var map = new google.maps.Map(mapCanvas, mapOptions);
    var home = new google.maps.Marker({position:myCenter});
    var monument = new google.maps.Marker({position:monumentLoc});
    
    //info for monument
    google.maps.event.addListener(monument,'click',function() {
            var monumentInfo = new google.maps.InfoWindow({
            content:"Where Texas won her independence!!"
        });
        monumentInfo.open(map,monument);
    });
    
    //info for home
    google.maps.event.addListener(home,'click',function() {
            var Info = new google.maps.InfoWindow({
            content:"Home Sweet Pineapple!",
            animation:google.maps.Animation.BOUNCE
        });
        Info.open(map,home);
    });
    
    
    //add makers to map
    home.setMap(map);
    monument.setMap(map);

}