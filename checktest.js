const fs = require('fs');
const axios = require('axios')
axios.get("http://api.dictionaryapi.dev/api/v2/entries/en/test").catch(function(err){console.log(err.code);process.exit(1)});
for (i = 2; i < process.argv.length; i++) {
    //console.log(array[i]);
    axios.get("http://api.dictionaryapi.dev/api/v2/entries/en/" + process.argv[i])
        .then((data) => { console.log(data.data[0].word); }).
        catch(function (err) { });
}
axios.get("http://api.dictionaryapi.dev/api/v2/entries/en/test").then(function(data){console.log("아직 사용 가능합니다.")}).catch(function(err){console.log("요청을 너무 많이 보냈습니다.당분간은 사용하지 마십시요.");});
