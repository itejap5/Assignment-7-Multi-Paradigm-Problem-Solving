(* Functional OCaml program for mean, median, mode *)

(* Sample input list *)
let data = [1; 2; 2; 3; 4; 5; 5; 5; 6]

(* Mean using fold_left *)
let mean lst =
  let sum = List.fold_left ( + ) 0 lst in
  (float_of_int sum) /. (float_of_int (List.length lst))

(* Median using List.sort and List.nth *)
let median lst =
  let sorted = List.sort compare lst in
  let n = List.length sorted in
  if n mod 2 = 1 then
    float_of_int (List.nth sorted (n / 2))
  else
    let a = List.nth sorted (n / 2 - 1) in
    let b = List.nth sorted (n / 2) in
    (float_of_int (a + b)) /. 2.0

(* Build frequency table as an association list *)
let freq_table lst =
  List.fold_left
    (fun acc x ->
      let count = match List.assoc_opt x acc with Some c -> c | None -> 0 in
      (x, count + 1) :: List.remove_assoc x acc)
    [] lst

(* Find mode(s) and frequency *)
let modes lst =
  let freq = freq_table lst in
  let maxc = List.fold_left (fun m (_, c) -> max m c) 0 freq in
  let only_max = List.filter (fun (_, c) -> c = maxc) freq in
  (List.map fst only_max, maxc)

(* Main execution *)
let () =
  let sorted = List.sort compare data in
  let (ms, c) = modes sorted in
  Printf.printf "Input: ";
  List.iter (fun x -> Printf.printf "%d " x) data;
  Printf.printf "\nMean: %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);
  Printf.printf "Mode(s): ";
  List.iter (fun x -> Printf.printf "%d " x) ms;
  Printf.printf " (freq = %d)\n" c