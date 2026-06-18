import chess
import heapq
from typing import List


# Piece values for material evaluation
PIECE_VALUES = {
    chess.PAWN: 1,
    chess.KNIGHT: 3,
    chess.BISHOP: 3,
    chess.ROOK: 5,
    chess.QUEEN: 9,
    chess.KING: 0,
}

# Large value for checkmate detection
CHECKMATE_SCORE = 10000


def evaluate_board(board: chess.Board) -> float:
    # Check for checkmate
    if board.is_checkmate():
        # If it's whites turn and checkmate, white lost
        if board.turn == chess.WHITE:
            return -CHECKMATE_SCORE
        else:
            return CHECKMATE_SCORE

    # Check for stalemate or draw
    if board.is_stalemate() or board.is_insufficient_material():
        return 0

    # Material counting
    score = 0
    for piece_type in PIECE_VALUES:
        # Count white pieces
        white_pieces = len(board.pieces(piece_type, chess.WHITE))
        # Count black pieces
        black_pieces = len(board.pieces(piece_type, chess.BLACK))
        # Add to score (white positive, black negative)
        score += PIECE_VALUES[piece_type] * (white_pieces - black_pieces)

    return score


def beam_search(board: chess.Board, beam_width: int, depth_limit: int):
    if depth_limit <= 0:
        return [], evaluate_board(board)

    # Determine if current player is white or black
    is_maximizing = board.turn == chess.WHITE

    # Initialize beam
    initial_eval = evaluate_board(board)
    beam = [(initial_eval, [], board.copy())]

    best_result = ([], initial_eval)

    for depth in range(depth_limit):
        candidates = []
        # Depth 0: original player's turn, Depth 1: opponent's turn, etc.
        current_maximizing = is_maximizing if depth % 2 == 0 else not is_maximizing

        for _, move_sequence, current_board in beam:
            legal_moves = list(current_board.legal_moves)

            # If no legal moves, this is either checkmate or stalemate
            if not legal_moves:
                eval_score = evaluate_board(current_board)
                candidates.append((eval_score, move_sequence, current_board.copy()))
                continue

            for move in legal_moves:
                # Make the move on a copy
                new_board = current_board.copy()
                new_board.push(move)

                # Evaluate the new position
                eval_score = evaluate_board(new_board)

                # Track the move sequence
                new_sequence = move_sequence + [move]

                candidates.append((eval_score, new_sequence, new_board))

        if not candidates:
            break

        # Select top beam_width candidates
        # For maximizing player: select highest scores (nlargest)
        # For minimizing player: select lowest scores (nsmallest)
        if current_maximizing:
            beam = heapq.nlargest(beam_width, candidates, key=lambda x: x[0])
        else:
            beam = heapq.nsmallest(beam_width, candidates, key=lambda x: x[0])

    # Return the best result from the final beam
    if beam:
        if is_maximizing:
            best = max(beam, key=lambda x: x[0])
        else:
            best = min(beam, key=lambda x: x[0])
        best_result = (best[1], best[0])

    return best_result


def format_move_sequence(moves: List[chess.Move], board: chess.Board):
    temp_board = board.copy()
    move_strs = []
    for move in moves:
        move_strs.append(temp_board.san(move))
        temp_board.push(move)
    return " -> ".join(move_strs)


# starting position
board = chess.Board()
beam_width = 4
depth_limit = 5

print("Starting position\n")
print(f"Board:\n{board}\n")
print(f"Beam Width: {beam_width}")
print(f"Depth Limit: {depth_limit}")
print(f"Turn: {'White' if board.turn == chess.WHITE else 'Black'}")
print()

best_moves, score = beam_search(board, beam_width, depth_limit)

print(f"Best Move Sequence: {format_move_sequence(best_moves, board)}")
print(f"Evaluation Score: {score}")
print()

# Position with checkmate
tactical_fen = "r1bqkbnr/pppp1ppp/2n5/4p3/2B1P3/5Q2/PPPP1PPP/RNB1K1NR w KQkq - 4 4"
board2 = chess.Board(tactical_fen)

print("Checkmate Opportunity\n")
print(f"Board:\n{board2}\n")
print(f"FEN: {tactical_fen}")
print(f"Beam Width: {beam_width}")
print(f"Depth Limit: {depth_limit}")
print()

best_moves2, score2 = beam_search(board2, beam_width, depth_limit)

print(f"Best Move Sequence: {format_move_sequence(best_moves2, board2)}")
print(f"Evaluation Score: {score2}")
print()

# Endgame position
endgame_fen = "8/8/8/5k2/8/8/4Q3/4K3 w - - 0 1"
board3 = chess.Board(endgame_fen)

print("Endgame position\n")
print(f"Board:\n{board3}\n")
print(f"FEN: {endgame_fen}")
print(f"Beam Width: {beam_width}")
print(f"Depth Limit: {depth_limit}")
print()

best_moves3, score3 = beam_search(board3, beam_width, depth_limit)

print(f"Best Move Sequence: {format_move_sequence(best_moves3, board3)}")
print(f"Evaluation Score: {score3}")
