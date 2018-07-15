let component = ReasonReact.reducerComponent("Todos");

type todo = {
	title: string,
	isDone: bool
};

/* Create variant for actions for the given todo */
type actions = 
	| ADD(todo)
	| REMOVE(int)
	| SET_DONE(int);


let make = (_children) => {
	...component,
	initialState: () => { todos: [] },
	reducer: (action, state) => {
		switch(action){
			| ADD(todo) => ReasonReact.Update({...state, todos: [state.todos, ...[todo]]})
		}
	},
	render: _self => {

	}
}