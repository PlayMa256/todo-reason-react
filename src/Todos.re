
type todo = {
	title: string,
	isDone: bool
};

type state = {
	todos: list(todo)
}

/* Create variant for actions for the given todo */
type actions = 
	| ADD(todo)
	| REMOVE(todo)
	| SET_DONE(todo);

let component = ReasonReact.reducerComponent("Todos");

let make = (_children) => {
	...component,
	initialState: () => { todos: [{
		title: "Mama mia",
		isDone: false
	}] },

	reducer: (action, state) => {
		switch(action){
			| ADD(todo) => ReasonReact.Update({todos: List.append(state.todos, [todo])})
			| REMOVE(todo) => {
				let result = List.filter((x) => x != todo, state.todos);
				ReasonReact.Update({
					todos: result
				})
			}
		}
	},

	render: self => {
		let lists = List.mapi((idx, todo) => {
			<Todo
				key={todo.title ++ " - " ++ string_of_int(idx)}
				title={todo.title}
				isDone={todo.isDone}
			/>
		}, self.state.todos);
		<div>
			<h1>(ReasonReact.string("Todos"))</h1>
			(ReasonReact.array(Array.of_list(lists)))
		</div>
	}
}