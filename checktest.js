const fs = require('fs');
const axios = require('axios')
console.log("console log")
for (i = 2; i < process.argv.length; i++) {
    //console.log(array[i]);
    axios.get("http://api.dictionaryapi.dev/api/v2/entries/en/" + process.argv[i])
        .then((data) => { console.log(data.data[0].word); }).
        catch(function (err) { });
}
