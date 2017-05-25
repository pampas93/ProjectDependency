window.onload=function(){
var graph = 
{"nodes":[{"name":"Utilities.h","group" : 0},{"name":"XmlDocument.h","group" : 1},{"name":"XmlElement.h","group" : 2},{"name":"itokcollection.h","group" : 3},{"name":"Tokenizer.h","group" : 3},{"name":"xmlElementParts.h","group" : 3},{"name":"XmlParser.h","group" : 4},{"name":"Utilities.cpp","group" : 0},{"name":"XmlDocument.cpp","group" : 1},{"name":"XmlElement.cpp","group" : 2},{"name":"Tokenizer.cpp","group" : 3},{"name":"xmlElementParts.cpp","group" : 3},{"name":"XmlParser.cpp","group" : 4}],"links":[{"source":11,"target":5,"value": 1},{"source":11,"target":4,"value": 1},{"source":6,"target":1,"value": 1},{"source":6,"target":2,"value": 1},{"source":6,"target":8,"value": 1},{"source":6,"target":3,"value": 1},{"source":6,"target":5,"value": 1},{"source":6,"target":4,"value": 1},{"source":6,"target":12,"value": 1},{"source":10,"target":4,"value": 1},{"source":1,"target":2,"value": 1},{"source":1,"target":6,"value": 1},{"source":1,"target":8,"value": 1},{"source":12,"target":6,"value": 1},{"source":12,"target":4,"value": 1},{"source":12,"target":1,"value": 1},{"source":12,"target":5,"value": 1},{"source":12,"target":8,"value": 1},{"source":12,"target":2,"value": 1},{"source":12,"target":0,"value": 1},{"source":5,"target":3,"value": 1},{"source":5,"target":4,"value": 1},{"source":5,"target":11,"value": 1},{"source":8,"target":2,"value": 1},{"source":8,"target":1,"value": 1},{"source":8,"target":6,"value": 1},{"source":7,"target":0,"value": 1},{"source":9,"target":2,"value": 1},{"source":0,"target":7,"value": 1},{"source":4,"target":10,"value": 1},{"source":2,"target":9,"value": 1}]};
var width = $( window ).width(),
    height = 500;

var color = d3.scale.category20();

var force = d3.layout.force()
    .charge(-700)
    .linkDistance(100)
    .size([width, height]);

var svg = d3.select("body").append("svg")
    .attr("width", width)
    .attr("height", height);
    
    svg.append("svg:defs").selectAll("marker")
    .data(["end"])      // Different link/path types can be defined here
  .enter().append("svg:marker")    // This section adds in the arrows
    .attr("id", String)
    .attr("viewBox", "0 -5 10 10")
    .attr("refX", 15)
    .attr("refY", -1.5)
    .attr("markerWidth", 6)
    .attr("markerHeight", 6)
    .attr("orient", "auto")
  .append("svg:path")
    .attr("d", "M0,-5L10,0L0,5")
    .style("stroke", "#4679BD")
    .style("opacity", "0.6");;


var drawGraph = function(graph) {
  force
      .nodes(graph.nodes)
      .links(graph.links)
      .start();

  var link = svg.selectAll(".link")
      .data(graph.links)
    .enter().append("line")
      .attr("class", "link")
          .attr("marker-end", "url(#end)")
      .style("stroke-width", function(d) { return 2; });

  var gnodes = svg.selectAll('g.gnode')
     .data(graph.nodes)
     .enter()
     .append('g')
     .classed('gnode', true);
    
  var node = gnodes.append("circle")
      .attr("class", "node")
      .attr("r", 10)
      .style("fill", function(d) { return color(d.group); })
      .call(force.drag)
      .on('dblclick', function(d){
        var url = "../CodePublishHTML/"+d.name+".html";

        var win = window.open(url, '_blank');
        win.focus();

//        window.alert(d.name);

      });


  var labels = gnodes.append("text")
      .attr("dx", 10)
      .attr("dy", ".35em")
      .text(function(d) { return d.name; });

  console.log(labels);
    
  force.on("tick", function() {
    link.attr("x1", function(d) { return d.source.x; })
        .attr("y1", function(d) { return d.source.y; })
        .attr("x2", function(d) { return d.target.x; })
        .attr("y2", function(d) { return d.target.y; });

    gnodes.attr("transform", function(d) { 
        return 'translate(' + [d.x, d.y] + ')'; 
    });
      
    
      
  });
};

drawGraph(graph);

}