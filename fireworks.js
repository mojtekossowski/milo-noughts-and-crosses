.pragma library

// Returns owner's tile color (with winning field info)
function getTileColor (owner, isWinningField){
    if (owner === 1){
        return isWinningField ? '#366399' : '#A6B7CC';
    }
    else if (owner === 2){
        return isWinningField ? '#CC4A3D' : '#FF9D80';
    }
    else{
        return 'gray'
    }
}

// Returns winner info status (idle, draw, first/second player name)
function getWinnerInfo(victory, first, second){
    if (victory < 0) {
        return 'Draw!'
    }
    if (victory === first.playerMarkType){
        return first.name + ' wins!'
    }
    if (victory === second.playerMarkType){
        return second.name + ' wins!'
    }

    return 'Tap to play!';
}

// Returns Nought/Cross image path
function getImage (owner){
    if (owner === 1){
        return 'qrc:/img/gfx/cross.png';
    }
    else if (owner === 2){
        return 'qrc:/img/gfx/nought.png';
    }
    else {
        return '';
    }
}

// Returns player's activity
function isPlayerActive(engine, playerId){
    return engine.active && (engine.currentPlayer === playerId);
}
