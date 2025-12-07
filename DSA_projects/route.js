const buildings = [
    "Main Gate",
    "Admin Block",
    "Classroom Block",
    "Library",
    "Hostel",
    "Canteen",
    "Sports Complex"
];

const INF = 1e9;

const graph = [
    [0,3,5,0,0,0,7],
    [3,0,2,4,0,0,0],
    [5,2,0,3,4,0,0],
    [0,4,3,0,0,2,0],
    [0,0,4,0,0,3,5],
    [0,0,0,2,3,0,4],
    [7,0,0,0,5,4,0]
];

function populateDropdowns() {
    let src = document.getElementById("src");
    let dest = document.getElementById("dest");

    buildings.forEach((b,i)=>{
        let o1=document.createElement("option");
        o1.value=i; o1.textContent=b;
        src.appendChild(o1);

        let o2=document.createElement("option");
        o2.value=i; o2.textContent=b;
        dest.appendChild(o2);
    });
}

function dijkstra(start){
    let n = buildings.length;
    let dist = Array(n).fill(INF);
    let used = Array(n).fill(false);
    let parent = Array(n).fill(-1);

    dist[start] = 0;

    for (let i=0; i<n; i++){
        let u=-1;
        for (let j=0; j<n; j++)
            if(!used[j] && (u===-1 || dist[j] < dist[u])) u=j;

        used[u]=true;

        for (let v=0; v<n; v++){
            if(graph[u][v] > 0){
                let nd = dist[u] + graph[u][v];
                if(nd < dist[v]){
                    dist[v] = nd;
                    parent[v] = u;
                }
            }
        }
    }
    return {dist, parent};
}

function buildPath(parent, target){
    let path=[];
    while(target !== -1){
        path.push(target);
        target = parent[target];
    }
    return path.reverse();
}

function findRoute(){
    let s = parseInt(document.getElementById("src").value);
    let d = parseInt(document.getElementById("dest").value);
    let result = document.getElementById("result");

    if(s===d){
        result.innerHTML = "You are already at "+buildings[s];
        return;
    }

    let {dist,parent} = dijkstra(s);
    let cost = dist[d];
    let path = buildPath(parent,d).map(x=>buildings[x]).join(" → ");

    result.innerHTML = `
        <b>Best Route:</b> ${path}<br>
        <b>Total Cost:</b> ${cost}
    `;
}

function showAll(){
    let s = parseInt(document.getElementById("src").value);
    let {dist,parent} = dijkstra(s);

    let out = "<b>Distances from "+buildings[s]+":</b><br><br>";

    for(let i=0;i<dist.length;i++){
        let path = buildPath(parent,i).map(x=>buildings[x]).join(" → ");
        out += `${buildings[i]} : ${dist[i]} (via ${path})<br>`;
    }

    document.getElementById("result").innerHTML = out;
}

function buildMap(){
    let map = document.getElementById("map");
    buildings.forEach((b,i)=>{
        let div = document.createElement("div");
        div.className="building";
        div.innerHTML = `<b>${b}</b><br>Node ${i}`;
        map.appendChild(div);
    });
}

window.onload = ()=>{
    populateDropdowns();
    buildMap();
};
