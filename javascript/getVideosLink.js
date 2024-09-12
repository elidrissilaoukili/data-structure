let goToBottom = setInterval(() => window.scrollBy(0, 400), 1000);

clearInterval(goToBottom);
    
    let arrayVideos = [];
    console.log('\n'.repeat(50));
    const links = document.querySelectorAll('a');
    for (const link of links) {
    
    if (link.id === "video-title") {
        link.href = link.href.split('&list=')[0];
        arrayVideos.push(link.title + ';' + link.href);
        console.log(link.title + '\t' + link.href);
    }
}	

let data = arrayVideos.join('\n');
let blob = new Blob([data], {type: 'text/csv'});
let elem = window.document.createElement('a');
elem.href = window.URL.createObjectURL(blob);
elem.download = 'my_data.csv';
document.body.appendChild(elem);
elem.click();
document.body.removeChild(elem);




// var script = document.createElement('script');
// script.src = 'path/to/code.js';  // Replace with the actual path
// document.head.appendChild(script);