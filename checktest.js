const fs=require('fs');
const axios=require('axios')
fs.readFile('./wow.txt','utf-8',function(error,data){
    console.log("console log")
    var array=data.toString().split("\n");
    for(i in array){
        //console.log(array[i]);
        axios.get("http://api.dictionaryapi.dev/api/v2/entries/en/"+array[i])
        .then((data)=>{console.log(data.data[0].word);}).
        catch(function(err){});
    }
})