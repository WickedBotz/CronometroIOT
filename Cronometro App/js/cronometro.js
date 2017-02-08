var ref = new Firebase("https://cronometroiot.firebaseio.com/analises");

function carregar(){
  $("#products-table tr").remove(); //Limpa tabela
  (function($) {
    // window.onload = function AddTableRow() {
      ref.once("value", function(snapshot) {
        var count = 0;
        snapshot.forEach(function(childSnapshot) {
          var childData = childSnapshot.val();
          var newRow = $("<tr>");
          var cols = "";
          count++;
          cols += '<td>'+count+'</td>';
          cols += '<td>'+childData.nome+'</td>';
          cols += '<td>'+childData.horas+':'+childData.minutos+':'+childData.segundos+':'+childData.centesimas+'</td>';
          newRow.append(cols);
          $("#products-table").append(newRow);
          return false;
        });
      });
    // };
  })(jQuery);
}
